#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PKPlayerCharacter.generated.h"

class UInputMappingContext;
class UCameraComponent;
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

	/*
	 * Components
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* FPVCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* FPVMesh;

	/*
	 * Input Mapping Context and Actions
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* IMC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value);

	void LookAround(const FInputActionValue& Value);

	/*
	 * Weapon
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	bool bHasWeapon = false;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetHasWeapon(bool bHasNewWeapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool GetHasWeapon();

	USkeletalMeshComponent* GetMeshFPV() const;

	UCameraComponent* GetFPVCameraComponent() const;


protected:
	virtual void BeginPlay() override;
};
