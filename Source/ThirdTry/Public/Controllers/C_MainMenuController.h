// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C_MainMenuController.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API AC_MainMenuController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Default")
	class UUserWidget* MainMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	TSubclassOf<class UUserWidget> menuClass;
protected:
	void BeginPlay();
};
