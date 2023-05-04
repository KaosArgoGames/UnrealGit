// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeBullet.generated.h"

UCLASS()
class THIRDTRY_API ACodeBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodeBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void K2_DestroyActor() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	float TimeToDestroy;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
