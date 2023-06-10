// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CodeWeapon.h"
#include "UObject/ConstructorHelpers.h"
#include "../../ThirdTry.h"

// Sets default values
ACodeWeapon::ACodeWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Skeleton = CreateDefaultSubobject<USkeletalMeshComponent>("Skeleton");
	Skeleton->SetupAttachment(RootComponent);

	canShoot = true;
	isLive = true;
}

// Called when the game starts or when spawned
void ACodeWeapon::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ACodeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ACodeBullet* ACodeWeapon::Attack()
{
	if(isLive)
	{
		ACodeBullet* outVar = NULL;
		if (canShoot)
		{
			canShoot = false;

			loc = Skeleton->GetSocketLocation("MuzzleFlashSocket");
			rot = Skeleton->GetSocketRotation("MuzzleFlashSocket");


			FActorSpawnParameters param;
			if (nullptr == Bullet)
			{
				UE_LOG(Game, Error, TEXT("Object is Nullptr in CodeWeapon.cpp"));
				return outVar;
			}
			else
			{
				AActor* Actor = GetWorld()->SpawnActor<AActor>(Bullet, loc, rot);

				outVar = Cast<ACodeBullet>(Actor);

				return outVar;
			}
			UE_LOG(Game, Warning, TEXT("Didn't Crash inside of Code Weapon"));
		}
		else
		{
			UE_LOG(Game, Error, TEXT("Blocking Shoot"));
			return outVar;
		}
	}
	return NULL;
}

void ACodeWeapon::ResetShoot(bool shoot)
{
	canShoot = shoot;
}

void ACodeWeapon::SpecialAttack()
{

}

bool ACodeWeapon::CanShoot()
{
	return canShoot;
}

void ACodeWeapon::PawnDied()
{
	isLive = false;
}