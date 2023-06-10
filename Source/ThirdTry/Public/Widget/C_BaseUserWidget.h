// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "C_BaseUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDTRY_API UC_BaseUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* reticle;
protected:
	virtual void NativeConstruct() override;
};
