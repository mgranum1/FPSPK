// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSPKInteractInterface.h"
#include "GameFramework/Actor.h"
#include "PKFPSSwitch.generated.h"

UCLASS()
class FPSPK_API APKFPSSwitch : public AActor, public IFPSPKInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APKFPSSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact_Implementation() override;

};
