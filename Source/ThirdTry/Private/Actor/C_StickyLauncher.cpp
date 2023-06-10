// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_StickyLauncher.h"

ACodeBullet* AC_StickyLauncher::Attack()
{
	Bullets.Add(Super::ACodeWeapon::Attack());

	//Was Causing Issues for something that was not causing issues
	//OnDestroyed.AddUniqueDynamic(this, &AC_StickyLauncher::RemoveBullet);

	return nullptr;
}

void AC_StickyLauncher::SpecialAttack()
{
	for (int i = 0; i < Bullets.Num(); i++)
	{
		Bullets[i]->SpecialAttack();
	}
	Bullets.Empty();
}

void AC_StickyLauncher::RemoveBullet(AActor* bullet)
{
	Bullets.Remove(Cast<ACodeBullet>(Bullet));
}