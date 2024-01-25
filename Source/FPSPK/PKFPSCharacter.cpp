// Fill out your copyright notice in the Description page of Project Settings.

#include "PKFPSCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"

// Sets default values
APKFPSCharacter::APKFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FPVMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
}

void APKFPSCharacter::Move(FInputActionValue& Value)
{
	//TO-DO MAKE THE CHARACTER MOVE PLZ.. NO ERROR NEXT CLASS
}

// Called when the game starts or when spawned
void APKFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APKFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APKFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent)
	{
		// EnhancedInputComponent->BindAction(MoveAction)
	}

}

