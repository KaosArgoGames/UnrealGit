// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PlayerChar.h"
#include "C_AICharacter.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_AICharacter : public APlayerChar
{
	GENERATED_BODY()
public:
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	AC_AICharacter();
};
