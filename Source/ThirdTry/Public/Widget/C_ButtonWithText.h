// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_ButtonWithText.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClick);
/**
 * 
 */
UCLASS()
class THIRDTRY_API UC_ButtonWithText : public UUserWidget
{
	GENERATED_BODY()
public:
	//Widget Stuff
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonBack;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* Information;
	//Non-Widget Stuff
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FText inText;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FOnClick OnClicked;

	UFUNCTION()
	void CallOnClick();
protected:
	void PreConstruct(bool IsDesignTime);
	virtual void NativeConstruct() override;
};
