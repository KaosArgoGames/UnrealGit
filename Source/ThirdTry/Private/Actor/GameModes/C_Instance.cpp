// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GameModes/C_Instance.h"
#include <Kismet/GameplayStatics.h>

void UC_Instance::LoadLevel(int lvl)
{
	if (levels[lvl].IsValid())
	{
		currentLevel = lvl;
	}
	UGameplayStatics::OpenLevel(this, levels[currentLevel]);
}

void UC_Instance::LoadGame()
{
	LoadLevel(Level1);
}

void UC_Instance::LoadMenu()
{
	LoadLevel(MainMenu);
}

void UC_Instance::Quit()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}

void UC_Instance::Reload()
{
	LoadLevel(currentLevel);
}
