// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_WinLose.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API UC_WinLose : public UUserWidget
{
	GENERATED_BODY()

	void NativePreConstruct() override;

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Variable")
		float timer = 3.5f;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UWidgetSwitcher* ChangeResult;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UVerticalBox* vertBox;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UC_ButtonWithText* reloadButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UC_ButtonWithText* quitButton;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Variable")
		class UC_Instance* gameRef;

	void Win();
	void ToMenu();
	void Restart();
};
