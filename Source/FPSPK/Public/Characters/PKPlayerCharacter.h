#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PKPlayerCharacter.generated.h"

struct FInputActionValue;
class UInputComponent;
class UInputAction;

UCLASS()
class FPSPK_API APKPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APKPlayerCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* FPVMesh;

	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;

	void Move(FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;
};
