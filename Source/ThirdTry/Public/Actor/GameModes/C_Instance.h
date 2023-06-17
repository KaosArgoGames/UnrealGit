// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "C_Instance.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API UC_Instance : public UGameInstance
{
	GENERATED_BODY()

	int MainMenu = 0;
	int Level1 = 1;
	int currentLevel;
private:
	void LoadLevel(int lvl);
public:
	void LoadGame();
	void LoadMenu();
	void Quit();
	void Reload();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
		TArray<FName> levels;
};
