// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CodeWeapon.h"
#include "../../ThirdTry.h"

// Sets default values
ACodeWeapon::ACodeWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodeWeapon::BeginPlay()
{
	Super::BeginPlay();
	Child = Cast<ACodeBullet>(Bullet);
}


// Called every frame
void ACodeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACodeWeapon::Attack()
{
	FVector loc = this->GetParentComponent()->GetSocketLocation("MuzzleFlashSocket");
	FRotator rot = this->GetParentComponent()->GetSocketRotation("MuzzleFlashSocket");
	FActorSpawnParameters param;
	if (nullptr == Child)
	{
		UE_LOG(Game, Error, TEXT("Object is Nullptr in CodeWeapon.cpp"));
	}
	else
	{
		AActor* Actor = GetWorld()->SpawnActor<AActor>(Child->GetClass(), loc, rot);
	}
	UE_LOG(Game, Warning, TEXT("Didn't Crash inside of Code Weapon"));
}
