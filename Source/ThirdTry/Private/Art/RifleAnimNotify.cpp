// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/RifleAnimNotify.h"
#include "../../ThirdTry.h"

void URifleAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UE_LOG(Game, Warning, TEXT("Throw Notify"));

}
