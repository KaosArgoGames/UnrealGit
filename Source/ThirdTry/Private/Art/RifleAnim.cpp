// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/RifleAnim.h"
#include "UObject/ConstructorHelpers.h"
#include "../../ThirdTry.h"

URifleAnim::URifleAnim()
{

}

void URifleAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();

	if (nullptr != Pawn)
	{
		FVector velocity = Pawn->GetVelocity();
		FRotator rotation = Pawn->GetActorRotation();
		Speed = velocity.Size();
		Direction = CalculateDirection(velocity, rotation);
	}
}

void URifleAnim::PersonUpdate_Implementation(int Choice)
{
	UE_LOG(Game, Error, TEXT("Shoot is True"));

	switch (Choice)
	{
	case 0:
		URifleAnim::AttackAnim_Implementation();
		break;
	case 1:
		URifleAnim::DamageAnim_Implementation();
		break;
	default:
		break;
	}	
}

void URifleAnim::AttackAnim_Implementation()
{
	PlaySlotAnimation(ShootAnim, FName("Action"));
}

void URifleAnim::DamageAnim_Implementation()
{
	PlaySlotAnimation(HurtAnim, FName("Damage"));
}

void URifleAnim::DeathAnim()
{
	deathNum = FMath::RandRange(0, DeathAnims.Num() - 1);

	UE_LOG(Game, Warning, TEXT("Current Death Anim = %d"), deathNum);

	CurDeathAnim = DeathAnims[deathNum];
}