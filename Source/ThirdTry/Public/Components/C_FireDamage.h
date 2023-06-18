// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "../Interface/C_DamageInterface.h"
#include "C_FireDamage.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API UC_FireDamage : public UDamageType, public IC_DamageInterface
{
	GENERATED_BODY()
public:
	void ApplyEffect(AActor* victim, AActor* attacker) const override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	TSubclassOf<class UActorComponent> sceneClass;
};
