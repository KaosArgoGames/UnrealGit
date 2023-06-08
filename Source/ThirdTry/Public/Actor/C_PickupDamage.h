// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/C_PickupBase.h"
#include "Particles/ParticleSystemComponent.h"
#include "C_PickupDamage.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_PickupDamage : public AC_PickupBase
{
	GENERATED_BODY()
public:
	AC_PickupDamage();
	void HandlePickup(AActor* OtherActor, const FHitResult& SweepResult) override;
	void PostPickup() override;
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
		class UFXSystemComponent* particle;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float Damage;
public:

};
