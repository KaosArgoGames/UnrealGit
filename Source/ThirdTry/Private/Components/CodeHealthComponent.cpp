// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CodeHealthComponent.h"
#include "../../ThirdTry.h"

// Sets default values for this component's properties
UCodeHealthComponent::UCodeHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	UCodeHealthComponent::InitHealth();
	// ...
}


// Called when the game starts
void UCodeHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UCodeHealthComponent::InitHealth();
	OnDamage.AddDynamic(this, &UCodeHealthComponent::HandleDamage);
}


// Called every frame
void UCodeHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCodeHealthComponent::InitHealth()
{
	CurrentHealth = MaxHealth;
}

void UCodeHealthComponent::HandleDamage(float damage)
{
	UE_LOG(Game, Warning, TEXT("Took Damage"));
	CurrentHealth -= damage;
	if (0.0f > CurrentHealth)
	{
		CurrentHealth = 0.0f;
		OnDamage.RemoveDynamic(this, &UCodeHealthComponent::HandleDamage);
	}
	else if (MaxHealth < CurrentHealth)
	{
		CurrentHealth = MaxHealth;
	}
	else
	{
		OnDamage.Broadcast(CurrentHealth);
	}

}

