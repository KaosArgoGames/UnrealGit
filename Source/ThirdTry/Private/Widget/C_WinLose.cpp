// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/C_WinLose.h"
#include <Actor/GameModes/C_Instance.h>
#include <Widget/C_ButtonWithText.h>
#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"

void UC_WinLose::NativePreConstruct()
{
	Super::NativePreConstruct();

	gameRef = Cast<UC_Instance>(GetGameInstance());

	reloadButton->OnClick.AddDynamic(this, &UC_WinLose::Restart);
	quitButton->OnClick.AddDynamic(this, &UC_WinLose::ToMenu);
}

void UC_WinLose::Win()
{
	vertBox->SetVisibility(ESlateVisibility::Hidden);
	ChangeResult->SetActiveWidgetIndex(1);
	FTimerHandle temp;
	GetWorld()->GetTimerManager().SetTimer(temp, this, &UC_WinLose::ToMenu, timer, false);
}

void UC_WinLose::ToMenu()
{
	gameRef->LoadMenu();
}

void UC_WinLose::Restart()
{
	gameRef->Reload();
}
