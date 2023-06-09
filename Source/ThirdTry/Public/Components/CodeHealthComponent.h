// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CodeHealthComponent.generated.h"

//Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamaged, float, update);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDTRY_API UCodeHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCodeHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	float MaxHealth;

	float update;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void InitHealth();
	UFUNCTION()
	void HandleDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	UFUNCTION()
	bool IsFullHealth();
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Default")
	FOnDamaged OnDamage;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Default")
	FOnDeath OnDeath;
private:
	UPROPERTY(VisibleAnywhere, Category = "Default");
	float CurrentHealth;
};
