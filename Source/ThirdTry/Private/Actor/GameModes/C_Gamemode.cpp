// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GameModes/C_Gamemode.h"
#include <Kismet/GameplayStatics.h>
#include <Actor/C_AIEnemy.h>
#include <Actor/C_Player.h>
#include "../../../ThirdTry.h"
#include "Blueprint/UserWidget.h"


void AC_Gamemode::BeginPlay()
{
	Super::BeginPlay();

	player = Cast<AC_Player>(UGameplayStatics::GetActorOfClass(GetWorld(), AC_Player::StaticClass()));
	player->OnDestroyed.AddDynamic(this, &AC_Gamemode::RemovePlayer);
	playerCon = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_AIEnemy::StaticClass(), enemies);
	enemyCount = enemies.Num();
	for (int i = 0; i < enemies.Num(); i++)
	{
		enemies[i]->OnDestroyed.AddDynamic(this, &AC_Gamemode::RemoveEnemy);
	}

	resUI = CreateWidget<UC_WinLose>(playerCon, resUIClass);
}

void AC_Gamemode::RemoveEnemy(AActor* destroyedActor)
{
	enemyCount--;

	if (enemyCount > 0)
	{
		UE_LOG(Game, Warning, TEXT("%d Enemies Remaining"), enemyCount);
	}
	else
	{
		player->DisableInput(playerCon);
		player->OnDestroyed.RemoveDynamic(this, &AC_Gamemode::RemovePlayer);

		AC_Player* temp = Cast<AC_Player>(player);
		temp->RemoveUI();

		resUI->Win();
		resUI->AddToViewport();
	}
}

void AC_Gamemode::RemovePlayer(AActor* destroyedActor)
{

	for (int i = 0; i < enemies.Num(); i++)
	{
		AC_AIEnemy* temp = Cast<AC_AIEnemy>(enemies[i]);
		if (temp)
		{
			temp->GameOver();
		}
	}
	playerCon->bShowMouseCursor = true;
	playerCon->SetInputMode(FInputModeUIOnly().SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways));

	AC_Player* temp = Cast<AC_Player>(player);
	temp->RemoveUI();

	resUI->AddToViewport();
}
