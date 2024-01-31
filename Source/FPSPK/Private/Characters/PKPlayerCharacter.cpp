#include "Characters/PKPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"

APKPlayerCharacter::APKPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	FPVMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));

}

void APKPlayerCharacter::Move(FInputActionValue& Value)
{
}

void APKPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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
		// EnhancedInputComponent->BindAction(MoveAction)
	}

}

