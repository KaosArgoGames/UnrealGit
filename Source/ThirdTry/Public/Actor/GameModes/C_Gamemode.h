// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "../../Widget/C_WinLose.h"
#include "C_Gamemode.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_Gamemode : public AGameModeBase
{
	GENERATED_BODY()
protected:
	TArray<AActor*> enemies;
	APawn* player;
	APlayerController* playerCon;

public:
	void BeginPlay();
	UFUNCTION()
	void RemoveEnemy(AActor* destroyedActor);
	UFUNCTION()
	void RemovePlayer(AActor* destroyedActor);

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	int enemyCount;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	UC_WinLose* resUI;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default");
	TSubclassOf<UUserWidget> resUIClass;
};
