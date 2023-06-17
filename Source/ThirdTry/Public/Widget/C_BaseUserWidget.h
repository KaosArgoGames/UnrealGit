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
	class UImage* Reticle;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UProgressBar* HealthBar;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FName color;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FVector destination;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FVector hit;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FLinearColor colorOne;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FLinearColor colorTwo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	class UMaterialInstanceDynamic* dynMat;
	UPROPERTY()
	bool hasHit;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float ratio;
	UFUNCTION()
	bool GetDest(FVector& shot, FVector& point);

	void UpdateHealthBar(float update);
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& Geo, float dTime) override;
	void ColorChange(FLinearColor inColor);
private:
	FVector2D posPixel;
	FVector2D posPort;
	FVector2D size;
	FVector posGlobal;
	FVector dirGlobal;
	FHitResult hitRes;
	FGeometry geometry;
};
