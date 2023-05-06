// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CodeBullet.h"
#include "../../ThirdTry.h"
#include <string>

// Sets default values
ACodeBullet::ACodeBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>("Sphere");
	Move = CreateDefaultSubobject<UProjectileMovementComponent>("Move");

	SphereCollision->SetupAttachment(RootComponent);
	Sphere->SetupAttachment(SphereCollision);
	Sphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>Asset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	Sphere->SetStaticMesh(Asset.Object);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ACodeBullet::BoundFunction);
	SphereCollision->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	Sphere->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	TimeToDestroy = 5.0f;
	TimeToAllowCollision = .25f;
}

// Called when the game starts or when spawned
void ACodeBullet::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(timer, this, &ACodeBullet::K2_DestroyActor, TimeToDestroy);
	GetWorld()->GetTimerManager().SetTimer(timer, this, &ACodeBullet::K2_DestroyActor, TimeToAllowCollision);
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

void ACodeBullet::AllowCollision()
{
	allowCollision = true;
}

void ACodeBullet::BoundFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(Game, Error, TEXT("Hit Object"));
	if (allowCollision && OtherActor != this)
	{
		ACodeBullet::K2_DestroyActor();
	}
}

