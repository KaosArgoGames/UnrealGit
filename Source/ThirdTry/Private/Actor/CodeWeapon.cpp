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

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>Asset(TEXT("SkeletalMesh'/Game/END_Starter/Guns/Rifle/SK_Rifle.SK_Rifle'"));
	Skeleton->SetSkeletalMesh(Asset.Object);
	canShoot = true;
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

void ACodeWeapon::Attack()
{
<<<<<<< Updated upstream
	if (ACodeWeapon::CanShoot())
	{
=======
	if (canShoot)
	{
		canShoot = false;
>>>>>>> Stashed changes
		FVector loc = Skeleton->GetSocketLocation("MuzzleFlashSocket");
		FRotator rot = Skeleton->GetSocketRotation("MuzzleFlashSocket");
		FActorSpawnParameters param;
		if (nullptr == Bullet)
		{
			UE_LOG(Game, Error, TEXT("Object is Nullptr in CodeWeapon.cpp"));
		}
		else
		{
			AActor* Actor = GetWorld()->SpawnActor<AActor>(Bullet, loc, rot);
		}
		UE_LOG(Game, Warning, TEXT("Didn't Crash inside of Code Weapon"));
<<<<<<< Updated upstream
		canShoot = false;
	}
=======
	}
	else
	{
		UE_LOG(Game, Error, TEXT("Blocking Shoot"));
	}
}

void ACodeWeapon::ResetShoot(bool shoot)
{
	canShoot = true;
>>>>>>> Stashed changes
}

bool ACodeWeapon::CanShoot()
{
	return canShoot;
<<<<<<< Updated upstream
}

void ACodeWeapon::ResetShoot()
{
	canShoot = true;
=======
>>>>>>> Stashed changes
}

