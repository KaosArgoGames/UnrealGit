// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RifleAnim.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API URifleAnim : public UAnimInstance
{
	GENERATED_BODY()
protected:
	URifleAnim();
	UAnimSequenceBase* ShootAnim;
	UAnimSequenceBase* HurtAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	float Direction;

public:
	bool shoot = false;
	void NativeUpdateAnimation(float DeltaSeconds) override;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default") 
	void PersonUpdate(int Choice);
	virtual void PersonUpdate_Implementation(int Choice);
};
