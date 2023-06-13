// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/CodeWeapon.h"
#include "Art/RifleAnim.h"
#include "GameFramework/Character.h"
#include <Components/CodeHealthComponent.h>
#include "../Interface/C_PickupInterface.h"
#include "C_StickyLauncher.h"

#include "PlayerChar.generated.h"


UCLASS()
class THIRDTRY_API APlayerChar : public ACharacter, public IC_PickupInterface
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	APlayerChar();
	ACodeWeapon* Weapon;
	URifleAnim* Anim;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components");
	UChildActorComponent* WeaponChildActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	TSubclassOf<AActor> WeaponClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	TSubclassOf<ACodeWeapon> RifleClass; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	TSubclassOf<AC_StickyLauncher> StickyClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default");
	UCodeHealthComponent* Health;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	UFUNCTION(BlueprintCallable, Category = "Function")
	void Attack();
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void HandleDeath();
	UFUNCTION(BlueprintCallable, Category = "Default")
	virtual void SpecialAttack();
	UFUNCTION()
	virtual void SwapWeapon();
	UFUNCTION()
	virtual void SetObjectRefs();

	//Interface Stuff
	bool CanPickup() override;
	bool ShouldPickup() override;
};
