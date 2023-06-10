// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "Particles/ParticleSystemComponent.h"
#include "../Interface/C_PickupInterface.h"
#include "../Actor/PlayerChar.h"
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
	UFUNCTION()
	void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void HandlePickup(AActor* OtherActor, const FHitResult& SweepResult);
	virtual void PostPickup();
private:
	virtual bool CanPickup(AActor* OtherActor);
};
