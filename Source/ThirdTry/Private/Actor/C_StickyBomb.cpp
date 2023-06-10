// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_StickyBomb.h"
#include "Engine/EngineTypes.h"
#include "../../ThirdTry.h"

void AC_StickyBomb::SpecialAttack()
{
	UE_LOG(Game, Warning, TEXT("Special Attack Called"));

	K2_DestroyActor();
}

void AC_StickyBomb::HandleOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, FHitResult SweepResult)
{
	USkeletalMeshComponent* skelly = Cast<USkeletalMeshComponent>(OtherComp->GetClass());

	if (skelly == NULL)
	{
		UE_LOG(Game, Error, TEXT("NULL"));
	}

	if (skelly != NULL)
	{
		Super::HandleOverlap(OtherActor, OtherComp, SweepResult);
	}
	else
	{
		SphereCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
		Move->StopMovementImmediately();
		GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	}
}
