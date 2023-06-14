// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PlayerChar.h"
#include "C_Player.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_Player : public APlayerChar
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	class USpringArmComponent* cameraMount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	class UCameraComponent* camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Default")
	class UUserWidget* HUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	TSubclassOf<class UUserWidget> hudClass;

	void BeginPlay();

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void HandleDeath();
public:
	AC_Player();
	//Interface Stuff
	bool CanPickup() override;
	bool ShouldPickup() override;
	void SpecialAttack();
private:

};
