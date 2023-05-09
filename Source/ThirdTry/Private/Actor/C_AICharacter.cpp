// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_AICharacter.h"


AC_AICharacter::AC_AICharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AC_AICharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AC_AICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Attack();
}

