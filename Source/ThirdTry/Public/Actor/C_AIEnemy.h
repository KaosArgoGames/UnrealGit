// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PlayerChar.h"
#include "C_AIEnemy.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_AIEnemy : public APlayerChar
{
	GENERATED_BODY()
	AC_AIEnemy();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
