// Fill out your copyright notice in the Description page of Project Settings.


#include "PKFPSSwitch.h"

// Sets default values
APKFPSSwitch::APKFPSSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APKFPSSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APKFPSSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APKFPSSwitch::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red,TEXT("Interact"));
}

