// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_PickupHealth.h"
#include "../../ThirdTry.h"
#include <Kismet/GameplayStatics.h>

AC_PickupHealth::AC_PickupHealth()
{
	particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System"));

	particle->SetupAttachment(collider);
	particle->SetWorldLocation(FVector(0.0f, 0.0f, -40.0f));
	particle->SetWorldScale3D(FVector(0.5f, 0.5f, 0.7f));

	collider->SetWorldScale3D(FVector(1.5f, 1.5f, 2.0f));
	Healing = 2;
}

void AC_PickupHealth::HandlePickup(AActor* OtherActor, const FHitResult& SweepResult)
{
	//Will not let me include the above line for some reason
	Super::HandlePickup(OtherActor, SweepResult);

	UE_LOG(Game, Error, TEXT("Healing Character"));
	UGameplayStatics::ApplyDamage(OtherActor, -Healing, GetInstigatorController(), this, 0);
}

bool AC_PickupHealth::CanPickup(AActor* OtherActor)
{
	APlayerChar* temp = Cast<APlayerChar>(OtherActor);

	if (temp->CanPickup())
	{
		return true;
	}
	return false;
}
