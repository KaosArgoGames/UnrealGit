// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/C_MainMenu.h"
#include "Widget/C_ButtonWithText.h"
#include <Kismet/KismetSystemLibrary.h>

void UC_MainMenu::NativePreConstruct()
{
	Super::NativePreConstruct();
	instance = Cast<UC_Instance>(GetGameInstance());
}

void UC_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	
	////instance = Cast<UC_Instance>(instClass);
	//UGameInstance* temp = GetGameInstance();
	//instance = Cast<UC_Instance>(temp);
	//instance = Cast<UC_Instance>(GetGameInstance());

	StartButton->OnClicked.AddDynamic(this, &UC_MainMenu::Start);
	EndButton->OnClicked.AddDynamic(this, &UC_MainMenu::Quit);
}

void UC_MainMenu::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}

void UC_MainMenu::Start()
{
	instance->LoadGame();
}
