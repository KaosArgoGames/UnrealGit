// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API UC_MainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* BackGround;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UVerticalBox* VertBox;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UC_ButtonWithText* StartButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UC_ButtonWithText* EndButton;

	virtual void NativeConstruct();

private:
	void Quit();
	void Start();
};
