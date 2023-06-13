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
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName color;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector destination;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector hit;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor colorOne;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor colorTwo;
	UFUNCTION()
	bool GetDest(FVector& shot, FVector& point);
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& Geo, float dTime) override;
	void ColorChange();
};
