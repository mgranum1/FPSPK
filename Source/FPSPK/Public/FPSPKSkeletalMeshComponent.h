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

	UFPSPKSkeletalMeshComponent();

	APKPlayerCharacter* Character;

	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Object")
	void AttachComponentToPlayer(APKPlayerCharacter* TargetCharacter);

	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponSettings")
	FVector GuntipOffset;

	/*
	 * IMC and Actions
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* FireIMC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* FireAction;

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Fire();

	//-----------------------------------------
	//-----------------------------------------
	//-----------------------------------------

	/*
	 * Animation and Sound
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation And Sound")
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation And Sound")
	UAnimMontage* FireAnimation;

	//-----------------------------------------
	//-----------------------------------------
	//-----------------------------------------

	/*
	 * Projectile
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
	TSubclassOf<AActor> ProjectileToSpawn;
};
