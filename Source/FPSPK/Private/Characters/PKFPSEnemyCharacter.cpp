// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PKFPSEnemyCharacter.h"

// Sets default values
APKFPSEnemyCharacter::APKFPSEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APKFPSEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APKFPSEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APKFPSEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

