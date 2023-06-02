// Fill out your copyright notice in the Description page of Project Settings.

#include <Art/RifleAnim.h>
#include "Art/Notify/C_ShootEnd.h"

void UC_ShootEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	URifleAnim* anim = Cast<URifleAnim>(MeshComp->GetAnimInstance());

	anim->OnResetShoot.Broadcast(true);
}