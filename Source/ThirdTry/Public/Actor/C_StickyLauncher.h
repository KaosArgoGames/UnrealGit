// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/CodeWeapon.h"
#include "C_StickyLauncher.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_StickyLauncher : public ACodeWeapon
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")	TArray<ACodeBullet*> Bullets;
public:
	ACodeBullet* Attack();
	void SpecialAttack() override;
	void RemoveBullet(AActor* bullet);
};
