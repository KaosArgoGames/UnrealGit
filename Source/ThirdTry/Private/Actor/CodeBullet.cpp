// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CodeBullet.h"
#include "../../ThirdTry.h"

// Sets default values
ACodeBullet::ACodeBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Declare Object
	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>("Sphere");

	//Declare Attachments
	SphereCollision->SetupAttachment(RootComponent);
	Sphere->SetupAttachment(SphereCollision);

	//Alter Variables
	SphereCollision->SetWorldScale3D(FVector(0.4f, 0.4f, 0.4f));
	SphereCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Sphere->SetWorldScale3D(FVector(0.4f, 0.4f, 0.4f));
	
}

// Called when the game starts or when spawned
void ACodeBullet::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle timer;
	UE_LOG(Game, Warning, TEXT("Bullet Created"));
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

