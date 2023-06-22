// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/C_ButtonWithText.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UC_ButtonWithText::CallOnClick()
{
	OnClicked.Broadcast();
}

void UC_ButtonWithText::PreConstruct(bool IsDesignTime)
{
	Super::PreConstruct(IsDesignTime);
}

void UC_ButtonWithText::NativeConstruct()
{
	Super::NativeConstruct();

	Information->SetText(inText);

	ButtonBack->OnClicked.AddDynamic(this, &UC_ButtonWithText::CallOnClick);
}
