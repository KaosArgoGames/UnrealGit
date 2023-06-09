// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CodeHealthComponent.h"
#include "../../ThirdTry.h"

// Sets default values for this component's properties
UCodeHealthComponent::UCodeHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;


	// ...
}


// Called when the game starts
void UCodeHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UCodeHealthComponent::HandleDamage);
	UCodeHealthComponent::InitHealth();
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

void UCodeHealthComponent::HandleDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(Game, Warning, TEXT("Took Damage"));
	float temp = CurrentHealth;
	temp -= Damage;
	temp = FMath::Clamp(temp, 0.0f, MaxHealth);


	if (temp < CurrentHealth)
	{

		update = temp / MaxHealth;
		OnDamage.Broadcast(update);
	}

	CurrentHealth = temp;

	FString outCurHealth = FString::SanitizeFloat(CurrentHealth);
	FString tempTwo = "Current Health = ";
	tempTwo.Append(outCurHealth);

	if (CurrentHealth == 0)
	{
		UE_LOG(Game, Warning, TEXT("Health Component Detatched"));
		OnDeath.Broadcast();
		GetOwner()->OnTakeAnyDamage.RemoveDynamic(this, &UCodeHealthComponent::HandleDamage);
	}
}

bool UCodeHealthComponent::IsFullHealth()
{
	if (CurrentHealth / MaxHealth > 0.99)
	{
		return true;
	}
	else
	{
		return false;
	}
}
