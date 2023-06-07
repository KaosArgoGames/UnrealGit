// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "C_PickupBase.generated.h"

UCLASS()
class THIRDTRY_API AC_PickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_PickupBase();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	UBoxComponent* collider;
public:	
	void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void HandlePickup(AActor* OtherActor, const FHitResult& SweepResult);
	void PostPickup();
};
