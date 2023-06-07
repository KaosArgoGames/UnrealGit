// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ChildActorComponent.h"
#include "../../ThirdTry.h"
#include <ThirdTry/Public/Actor/CodeWeapon.h>

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
	Super::HandleDeath();
	DisableInput(GetWorld()->GetFirstPlayerController());
}
