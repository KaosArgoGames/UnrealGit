// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_DoTFire.generated.h"

UCLASS()
class THIRDTRY_API AC_DoTFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_DoTFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	UParticleSystemComponent* particles;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	TSubclassOf<class UDamageType> damageType;
};
