// Fill out your copyright notice in the Description page of Project Settings.

#include "RocketTanks.h"
#include "tank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	///Checks to make sure AI can see player
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController is missing!"))
	}
	else { UE_LOG(LogTemp, Warning, TEXT(" AIController Begin Play %s"), *(PlayerTank->GetName())) }
	///Checks to make sure AI is controlling a tank
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT(" AI Controller not found!"))
	}
	else { UE_LOG(LogTemp, Warning, TEXT(" AIController Begin Play %s"), *(ControlledTank->GetName())) }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO move toards player

		//aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//fire if ready

	}
	
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerTank);
}