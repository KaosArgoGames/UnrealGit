// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeWeapon.generated.h"

UCLASS()
class THIRDTRY_API ACodeWeapon : public AActor
{
	GENERATED_BODY()
		ACodeWeapon* Child;


public:	
	// Sets default values for this actor's properties
	ACodeWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	TSubclassOf<AActor> Bullet;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Function")
	void Attack();
};
