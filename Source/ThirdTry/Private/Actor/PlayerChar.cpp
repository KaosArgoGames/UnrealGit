// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerChar.h"
#include "../../ThirdTry.h"

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetWorldRotation(FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetWorldLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetWorldScale3D(FVector(0.95f, 0.95f, 0.95f));
}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	Child = Cast<ACodeWeapon>(WeaponChildActor->GetChildActor());
	Anim = Cast<URifleAnim>(GetMesh()->GetAnimInstance());
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerChar::Attack()
{
	UE_LOG(Game, Warning, TEXT("Didn't Crash"));
	if (nullptr != Anim)
	{
		Anim->PersonaUpdate();
	}
	Child->Attack();
}

