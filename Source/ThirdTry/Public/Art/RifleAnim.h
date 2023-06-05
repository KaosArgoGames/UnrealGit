// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RifleAnim.generated.h"
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResetShoot, bool, resetShoot);

UCLASS()
class THIRDTRY_API URifleAnim : public UAnimInstance
{
	GENERATED_BODY()
protected:
	URifleAnim();
	UAnimSequenceBase* ShootAnim;
	UAnimSequenceBase* HurtAnim;
	UAnimSequenceBase* CurDeathAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	TArray<UAnimSequenceBase*> DeathAnims;

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

	

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default")
	void AttackAnim();
	virtual void AttackAnim_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default")
	void DamageAnim();
	virtual void DamageAnim_Implementation();
	FOnResetShoot OnResetShoot;
};
