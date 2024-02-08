// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPKSkeletalMeshComponent.h"

void UFPSPKSkeletalMeshComponent::AttachComponentToPlayer(APKPlayerCharacter* TargetCharacter)
{
	Character = TargetCharacter;

	if (Character == nullptr || Character->GetHasWeapon())
	{
		return;
	}

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	AttachToComponent(Character->GetMeshFPV(), AttachmentRules, FName(TEXT("AttachSocket")));

	Character->SetHasWeapon(true);
}

void UFPSPKSkeletalMeshComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Character == nullptr)
	{
		return;
	}
}
