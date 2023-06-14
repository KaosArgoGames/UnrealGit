// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ChildActorComponent.h"
#include "../../ThirdTry.h"
#include <ThirdTry/Public/Actor/CodeWeapon.h>
#include <Widget/C_BaseUserWidget.h>
#include <Kismet/GameplayStatics.h>
#include "Blueprint/UserWidget.h"
#include "Widget/C_BaseUserWidget.h"

AC_Player::AC_Player()
{
	//Create Components
	cameraMount = CreateDefaultSubobject<USpringArmComponent>("cameraMount");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");

	//Attach Components
	cameraMount->SetupAttachment(RootComponent);
	camera->SetupAttachment(cameraMount, USpringArmComponent::SocketName);

	//Assign Variables
	cameraMount->bUsePawnControlRotation = true;
	cameraMount->SetRelativeLocationAndRotation(FVector(0.0f, 80.0f, 30.f), FRotator(0.0f, 0.0f, 0.0f));
	cameraMount->TargetArmLength = 210.0f;
	camera->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));

}



void AC_Player::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget<UC_BaseUserWidget>(GetWorld()->GetFirstPlayerController(), hudClass);
	//FInputModeGameAndUI Mode;
	//Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture);
	//Mode.SetHideCursorDuringCapture(false);
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(Mode);
	HUD->AddToViewport();
}

void AC_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Rotation
	PlayerInputComponent->BindAxis("TurnTo", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AC_Player::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AC_Player::MoveRight);
	//Combat
	PlayerInputComponent->BindAction("StandardAttack", EInputEvent::IE_Pressed, this, &APlayerChar::Attack);
	PlayerInputComponent->BindAction("SpecialAttack", EInputEvent::IE_Pressed, this, &APlayerChar::SpecialAttack);
	PlayerInputComponent->BindAction("SwapWeapons", EInputEvent::IE_Pressed, this, &APlayerChar::SwapWeapon);
}
void AC_Player::MoveForward(float AxisValue)
{
	FRotator MakeRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);

	AddMovementInput(MakeRotation.Vector(), AxisValue);
}
void AC_Player::MoveRight(float AxisValue)
{
	FRotationMatrix MakeRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);

	AddMovementInput(MakeRotation.GetScaledAxis(EAxis::Y), AxisValue);
}

void AC_Player::HandleDeath()
{
	SetActorEnableCollision(false);
	DisableInput(GetWorld()->GetFirstPlayerController());
}


bool AC_Player::CanPickup()
{
	return ShouldPickup();
}

bool AC_Player::ShouldPickup()
{
	if (!Health->IsFullHealth())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AC_Player::SpecialAttack()
{
	Super::SpecialAttack();
}
