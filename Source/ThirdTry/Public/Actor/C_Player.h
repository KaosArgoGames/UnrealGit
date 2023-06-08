// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PlayerChar.h"
#include "../Interface/C_PickupInterface.h"
#include "C_Player.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_Player : public APlayerChar, IC_PickupInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	class USpringArmComponent* cameraMount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	class UCameraComponent* camera;

	void BeginPlay();

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void HandleDeath();
public:
	AC_Player();
private:
	bool ShouldPickup();
};
