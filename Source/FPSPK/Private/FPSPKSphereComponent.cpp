// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSPKSphereComponent.h"

#include "Kismet/GameplayStatics.h"

UFPSPKSphereComponent::UFPSPKSphereComponent()
{
	SphereRadius = 30.f;
}

void UFPSPKSphereComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UFPSPKSphereComponent::OnSphereBeginOverlap);
}

void UFPSPKSphereComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APKPlayerCharacter* Character = Cast<APKPlayerCharacter>(OtherActor);
	if (Character != nullptr)
	{
		OnPickUp.Broadcast(Character);
		OnComponentBeginOverlap.RemoveAll(this);
	}
}