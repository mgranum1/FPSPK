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
public:
	UFPSPKSkeletalMeshComponent() = default;

	APKPlayerCharacter* Character;

	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Object")
	void AttachComponentToPlayer(APKPlayerCharacter* TargetCharacter);

	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
