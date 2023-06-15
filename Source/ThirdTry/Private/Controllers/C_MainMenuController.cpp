// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/C_MainMenuController.h"
#include "Blueprint/UserWidget.h"
#include "Widget/C_MainMenu.h"

void AC_MainMenuController::BeginPlay()
{
	Super::BeginPlay();
	MainMenu = CreateWidget<UC_MainMenu>(GetWorld()->GetFirstPlayerController(), menuClass);
	MainMenu->AddToViewport();
}
