#include "Characters/PKPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

APKPlayerCharacter::APKPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	/*Camera Component*/
	FPCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	FPCameraComponent->SetupAttachment(GetCapsuleComponent());

	/*Skeletal Mesh Component*/
	FPVMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
	FPVMesh->SetupAttachment(FPCameraComponent);

}

void APKPlayerCharacter::Move(FInputActionValue& Value)
{
}

void APKPlayerCharacter::LookAround(FInputActionValue& Value)
{

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

	}

}

