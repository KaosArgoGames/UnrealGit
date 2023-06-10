// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_PickupBase.h"
#include "../../ThirdTry.h"

// Sets default values
AC_PickupBase::AC_PickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	collider = CreateDefaultSubobject<UBoxComponent>("Box");

	collider->SetupAttachment(RootComponent);

	collider->OnComponentBeginOverlap.AddDynamic(this, &AC_PickupBase::Overlap);
}

void AC_PickupBase::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CanPickup(OtherActor))
	{
		HandlePickup(OtherActor, SweepResult);
		PostPickup();
	}
}

void AC_PickupBase::HandlePickup(AActor* OtherActor, const FHitResult& SweepResult)
{
}

void AC_PickupBase::PostPickup()
{
	K2_DestroyActor();
}

bool AC_PickupBase::CanPickup(AActor* OtherActor)
{
	return true;
}
