// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/RifleAnim.h"

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
