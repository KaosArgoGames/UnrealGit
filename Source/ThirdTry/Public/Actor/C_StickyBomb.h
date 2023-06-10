// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/CodeBullet.h"
#include "C_StickyBomb.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_StickyBomb : public ACodeBullet
{
	GENERATED_BODY()
	
public:
	void SpecialAttack() override;
	void HandleOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, FHitResult SweepResult) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		float radius;
};
