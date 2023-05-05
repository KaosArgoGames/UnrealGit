// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CodeBullet.h"
#include "../../ThirdTry.h"

// Sets default values
ACodeBullet::ACodeBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodeBullet::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle timer;
	GetWorld()->GetTimerManager().SetTimer(timer, this, &ACodeBullet::K2_DestroyActor, TimeToDestroy);
}

void ACodeBullet::K2_DestroyActor()
{
	UE_LOG(Game, Error, TEXT("Time's Up"));
	Super::K2_DestroyActor();
}

// Called every frame
void ACodeBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

