// Fill out your copyright notice in the Description page of Project Settings.

#include "Actor/C_AIEnemy.h"
#include "../../ThirdTry.h"

AC_AIEnemy::AC_AIEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AC_AIEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(Game, Error, TEXT("Enemy AI Has Shot"));
	
	Attack();
}
