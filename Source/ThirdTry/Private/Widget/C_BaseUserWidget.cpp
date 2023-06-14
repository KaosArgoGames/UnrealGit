// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/C_BaseUserWidget.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Blueprint/SlateBlueprintLibrary.h>

bool UC_BaseUserWidget::GetDest(FVector& shot, FVector& point)
{
	shot = point;

	point = destination;

	return hasHit;
}

void UC_BaseUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	dynMat = Reticle->GetDynamicMaterial();
	Reticle->SetBrushFromMaterial(dynMat);
	ColorChange(colorOne);
}

void UC_BaseUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	geometry = Reticle->GetCachedGeometry();
	size = geometry.GetAbsoluteSize();
	size = size / 2.0f;

	USlateBlueprintLibrary::LocalToViewport(GetWorld(), geometry, FVector2D(0, 0), posPixel, posPort);
	
	posPixel += size;

	GetOwningPlayer()->DeprojectScreenPositionToWorld(posPixel.X, posPixel.Y, posGlobal, dirGlobal);
	destination = posGlobal + (dirGlobal * 100000);

	TArray<TEnumAsByte<EObjectTypeQuery>> objs{ UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic), UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn) };
	TArray<AActor*> ignoredActors{ GetOwningPlayerPawn() };
	hasHit = UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), posGlobal, destination, objs, false, ignoredActors, EDrawDebugTrace::None, hitRes, true);

	if (hasHit)
	{
		hit = hitRes.Location;
		APawn* p = Cast<APawn>(hitRes.Actor);

		if (p)
		{
			ColorChange(colorTwo);
		}
		else
		{
			ColorChange(colorOne);
		}
	}
	else
	{
		ColorChange(colorOne);
	}
}

void UC_BaseUserWidget::ColorChange(FLinearColor inColor)
{
	dynMat->SetVectorParameterValue(color, colorOne);
}
