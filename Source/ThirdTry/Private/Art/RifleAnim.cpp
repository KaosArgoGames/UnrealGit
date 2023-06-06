// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/RifleAnim.h"
#include "UObject/ConstructorHelpers.h"
#include "../../ThirdTry.h"

URifleAnim::URifleAnim()
{

	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase>GetAsset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Fire_Ironsights.A_Fire_Ironsights'"));
	if (nullptr != GetAsset.Object)
	{
		UE_LOG(Game, Warning, TEXT("Shoot Animation found"));
		ShootAnim = GetAsset.Object;
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Shoot Animation Not Found"));
	}
	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase>HurtAsset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Hit_Ironsights.A_Hit_Ironsights'"));
	if (nullptr != GetAsset.Object)
	{
		UE_LOG(Game, Warning, TEXT("Hurt Animation found"));
		HurtAnim = GetAsset.Object;
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Hurt Animation Not Found"));
	}
	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase>DeadAsset1(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Death1_Ironsights.A_Death1_Ironsights'"));
	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase>DeadAsset2(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Death2_Ironsights.A_Death2_Ironsights'"));
	if (nullptr != DeadAsset1.Object)
	{
		UE_LOG(Game, Warning, TEXT("Death Animation 1 found"));
		DeathAnims.Add(DeadAsset1.Object);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Death Animation 1 Not Found"));
	}
	if (nullptr != DeadAsset1.Object)
	{
		UE_LOG(Game, Warning, TEXT("Death Animation 2 found"));
		DeathAnims.Add(DeadAsset2.Object);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("Death Animation 2 Not Found"));
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
	dead = true;
	CurDeathAnim = DeathAnims[FMath::RandRange(0, DeathAnims.Num())];
}