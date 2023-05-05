// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CodeWeapon.h"
#include "../../ThirdTry.h"

// Sets default values
ACodeWeapon::ACodeWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Declare Variables
	Skeleton = CreateDefaultSubobject<USkeletalMeshComponent>("Skeleton");

	//Attach Variables
	Skeleton->SetupAttachment(RootComponent);
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
	FVector loc = Skeleton->GetSocketLocation("MuzzleFlashSocket");
	//FVector loc = this->GetParentComponent()->GetSocketLocation("MuzzleFlashSocket");
	FRotator rot = Skeleton->GetSocketRotation("MuzzleFlashSocket");
	//FRotator rot = this->GetParentComponent()->GetSocketRotation("MuzzleFlashSocket");
	FActorSpawnParameters param;
	//if (nullptr == Child)
	if (nullptr == Bullet)
	{
		UE_LOG(Game, Error, TEXT("Object is Nullptr in CodeWeapon.cpp"));
	}
	else
	{
		AActor* Actor = GetWorld()->SpawnActor<AActor>(Bullet, loc, rot);
	}
	UE_LOG(Game, Warning, TEXT("Didn't Crash inside of Code Weapon"));
}
