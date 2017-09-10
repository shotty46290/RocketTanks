// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketTanks.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "../Public/TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed)
{
	
	if (!Barrel) { return; }
	FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//calculate launch velocity
	auto DesiredAimDirection = LaunchVelocity.GetSafeNormal();
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		LaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	
	if (bHaveAimSolution)
	{
		auto AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	
	
	auto OurTankName = GetOwner()->GetName();
	auto AimDirection = LaunchVelocity.GetSafeNormal();
	UE_LOG(LogTemp, Warning, TEXT("%s Aimaing at: %s"), *OurTankName, *AimDirection.ToString());
	
	// if no sollution found do nothing
}

void UTankAimingComponent::SetBarrelRefrence(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// workout difference between current barrel rotation, and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch); //TODO Remove Magic number
}
