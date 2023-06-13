// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/C_BaseUserWidget.h"

bool UC_BaseUserWidget::GetDest(FVector& shot, FVector& point)
{
	return false;
}

void UC_BaseUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UC_BaseUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UC_BaseUserWidget::ColorChange()
{
}
