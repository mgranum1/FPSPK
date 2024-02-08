// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/PKPlayerCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "FPSPKSkeletalMeshComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class FPSPK_API UFPSPKSkeletalMeshComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

	APKPlayerCharacter* Character;

	UFUNCTION(Blueprintable, Category = "Object")
	void AttachComponentToPlayer(APKPlayerCharacter* TargetCharacter);

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
