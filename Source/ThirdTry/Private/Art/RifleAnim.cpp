// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/RifleAnim.h"
#include "UObject/ConstructorHelpers.h"
#include "../../ThirdTry.h"

URifleAnim::URifleAnim()
{

	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase>Asset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Fire_Ironsights.A_Fire_Ironsights'"));
	if (nullptr != Asset.Object)
	{
		UE_LOG(Game, Warning, TEXT("Animation found"));
		Animation = Asset.Object;
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

	if (shoot)
	{
		URifleAnim::PersonaUpdate();
	}
}

void URifleAnim::PersonaUpdate()
{
	UE_LOG(Game, Error, TEXT("Shoot is True"));

	//PlaySlotAnimation(Animation, "Attack");
	PlaySlotAnimationAsDynamicMontage(Animation, FName("Action"));

	shoot = false;
}
