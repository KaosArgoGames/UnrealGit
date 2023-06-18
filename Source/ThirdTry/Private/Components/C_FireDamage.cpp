// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/C_FireDamage.h"
#include <Interface/C_Scene.h>

void UC_FireDamage::ApplyEffect(AActor* victim, AActor* attacker) const
{
	UActorComponent* temp = victim->GetComponentByClass(sceneClass);
	if (temp != NULL)
	{
		UC_Scene* scene = Cast<UC_Scene>(temp);
		scene->BeginEffect(EEffectType::Fire_Damage, attacker);
	}
}
