// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/RifleAnim.h"
#include "UObject/ConstructorHelpers.h"
#include "../../ThirdTry.h"

URifleAnim::URifleAnim()
{

	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase>ShootAsset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Fire_Ironsights.A_Fire_Ironsights'"));
	if (nullptr != ShootAsset.Object)
	{
		UE_LOG(Game, Warning, TEXT("Animation found"));
		ShootAnim = ShootAsset.Object;
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Animation Not Found"));
	}
	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase>HurtAsset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Hit_Ironsights.A_Hit_Ironsights'"));
		if (nullptr != HurtAsset.Object)
		{
			UE_LOG(Game, Warning, TEXT("Animation found"));
			HurtAnim = HurtAsset.Object;
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("Animation Not Found"));
		}
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
<<<<<<< Updated upstream
}

void URifleAnim::AttackAnim_Implementation()
{
	PlaySlotAnimationAsDynamicMontage(ShootAnim, FName("Action"));
}

void URifleAnim::DamageAnim_Implementation()
{
	PlaySlotAnimationAsDynamicMontage(HurtAnim, FName("Action"));
}
=======

	shoot = false;
}
>>>>>>> Stashed changes
