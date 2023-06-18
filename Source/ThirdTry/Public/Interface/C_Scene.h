// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "C_Scene.generated.h"
UENUM(BlueprintType)
enum class EEffectType : uint8
{
	Fire_Damage		UMETA(DisplayName = "Fire"),
	NumEffects	UMETA(Hidden)
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDTRY_API UC_Scene : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UC_Scene();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void BeginEffect(EEffectType Effect, AActor* Causer);
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<class AFireEffect> FireClass;
};
