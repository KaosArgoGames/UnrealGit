// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_PickupDamage.h"
#include "../../ThirdTry.h"
#include <Kismet/GameplayStatics.h>

AC_PickupDamage::AC_PickupDamage()
{
	particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System"));

	particle->SetupAttachment(collider);
	particle->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	particle->SetWorldScale3D(FVector(0.4f, 0.4f, 0.25f));

	Damage = 2;
}

void AC_PickupDamage::HandlePickup(AActor* OtherActor, const FHitResult& SweepResult)
{
	Super::HandlePickup(OtherActor, SweepResult);
	UE_LOG(Game, Error, TEXT("Damage Pickup Interacted with"));
	UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, 0);
}

void AC_PickupDamage::PostPickup()
{
}
