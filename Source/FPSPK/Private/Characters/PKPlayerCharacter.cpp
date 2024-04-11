#include "Characters/PKPlayerCharacter.h"

#include "EngineUtils.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "FPSPKInteractInterface.h"
#include "InputAction.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

APKPlayerCharacter::APKPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	///*SpringArm Component*/
	//SpingArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	//SpingArm->SetupAttachment(GetRootComponent());

	/*Camera Component*/
	FPVCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	FPVCameraComponent->SetupAttachment(GetCapsuleComponent());
	FPVCameraComponent->bUsePawnControlRotation = true;

	/*Skeletal Mesh Component*/
	FPVMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
	FPVMesh->SetupAttachment(FPVCameraComponent);
}

void APKPlayerCharacter::Move(const FInputActionValue& Value)
{
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Emerald, TEXT("Triggering the move function"));

	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void APKPlayerCharacter::LookAround(const FInputActionValue& Value)
{
	FVector2D LookAroundVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAroundVector.X);
		AddControllerPitchInput(LookAroundVector.Y);
	}
}

void APKPlayerCharacter::InteractWithObjects(const FInputActionValue& Value)
{
	FVector StartTrace = GetFPVCameraComponent()->GetComponentLocation();
	FVector EndTrace = StartTrace + GetFPVCameraComponent()->GetComponentRotation().Vector() * InteractRange;

	FHitResult HitResult;
	FCollisionQueryParams CollisionsParams;
	CollisionsParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, CollisionsParams))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.GetActor()->GetName());
		if (HitResult.GetActor()->Implements<UFPSPKInteractInterface>())
		{
			IFPSPKInteractInterface::Execute_Interact(HitResult.GetActor());
		}
	}
	DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, 3.0f);

	
}


void APKPlayerCharacter::SetHasWeapon(bool bHasNewWeapon)
{
	bHasWeapon = bHasNewWeapon;
}

bool APKPlayerCharacter::GetHasWeapon()
{
	return bHasWeapon;
}

USkeletalMeshComponent* APKPlayerCharacter::GetMeshFPV() const
{
	return FPVMesh;
}

UCameraComponent* APKPlayerCharacter::GetFPVCameraComponent() const
{
	return FPVCameraComponent;
}

float APKPlayerCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	//return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health -= DamageAmount;
	if (Health <= 0)
	{
		Destroy();
	}
	return DamageAmount;
}

void APKPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Adding the Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC, 0);
		}
	}
}

void APKPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APKPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APKPlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APKPlayerCharacter::LookAround);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &APKPlayerCharacter::InteractWithObjects);
	}
}