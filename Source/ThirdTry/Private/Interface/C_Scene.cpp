// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/C_Scene.h"

// Sets default values for this component's properties
UC_Scene::UC_Scene()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UC_Scene::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UC_Scene::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UC_Scene::BeginEffect(EEffectType Effect, AActor* Causer)
{
	FActorSpawnParameters SpawnP;
	SpawnP.Owner = Causer;/*
	AActor* FireEffect = NULL;*/
	switch (Effect)
	{
	case EEffectType::Fire_Damage:/*
		FireEffect = GetWorld()->SpawnActor<AActor>(FireClass.Get(), GetComponentTransform(), SpawnP);
		FireEffect->AttachToActor(GetOwner(), FAttachmentTransformRules::SnapToTargetIncludingScale);*/
		break;
	case EEffectType::NumEffects:
		break;
	}
}

