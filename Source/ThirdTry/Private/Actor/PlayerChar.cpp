// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerChar.h"
#include "../../ThirdTry.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ChildActorComponent.h"
#include <ThirdTry/Public/Actor/CodeWeapon.h>

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	GetMesh()->SetWorldRotation(FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetWorldLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetWorldScale3D(FVector(0.95f, 0.95f, 0.95f));
	
	Health = CreateDefaultSubobject<UCodeHealthComponent>("Health");

	WeaponChildActor = CreateDefaultSubobject<UChildActorComponent>("WeaponChildActor");
	WeaponChildActor->SetupAttachment(GetMesh(), "WeaponTransform");
}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	//Casting
	WeaponChildActor->SetChildActorClass(WeaponClass);
<<<<<<< Updated upstream
	Child = Cast<ACodeWeapon>(WeaponChildActor->GetChildActor());
	Anim = Cast<URifleAnim>(GetMesh()->GetAnimInstance());

	//Binding
	Health->OnDamage.AddDynamic(this, &APlayerChar::TakeDamage);

=======

	//On Start Casts
	Child = Cast<ACodeWeapon>(WeaponChildActor->GetChildActor());
	Anim = Cast<URifleAnim>(GetMesh()->GetAnimInstance());

	//Add Dynamics
	Health->OnDamage.AddDynamic(this, &APlayerChar::TakeDamage);
	Anim->OnResetShoot.AddDynamic(Child, &ACodeWeapon::ResetShoot);
>>>>>>> Stashed changes
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
	if (Child->CanShoot())
	{
		UE_LOG(Game, Warning, TEXT("Didn't Crash"));
		if (nullptr != Anim)
		{
			Anim->PersonUpdate(0);
		}
		Child->Attack();
	}
}

void APlayerChar::TakeDamage(float Damage)
{
	UE_LOG(Game, Error, TEXT("PlayerChar.cpp Take Damage Called"))

	if (nullptr != Anim)
	{
		Anim->PersonUpdate(1);
	}
}

