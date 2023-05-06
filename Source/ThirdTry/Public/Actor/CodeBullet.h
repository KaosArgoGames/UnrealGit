// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include "CodeBullet.generated.h"

UCLASS()
class THIRDTRY_API ACodeBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodeBullet();

	FTimerHandle timer;
	bool allowCollision = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void K2_DestroyActor() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	USphereComponent* SphereCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	UStaticMeshComponent* Sphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	UProjectileMovementComponent* Move;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	float TimeToDestroy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	float TimeToAllowCollision;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AllowCollision();
private:
	UFUNCTION(BlueprintCallable, Category = "Function")
	void BoundFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
