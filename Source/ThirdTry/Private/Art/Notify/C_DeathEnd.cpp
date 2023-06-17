// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/Notify/C_DeathEnd.h"
#include <Art/RifleAnim.h>

void UC_DeathEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	URifleAnim* anim = Cast<URifleAnim>(MeshComp->GetAnimInstance());

	anim->OnDeathEnd.Broadcast();
}
