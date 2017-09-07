// Fill out your copyright notice in the Description page of Project Settings.

#include "RocketTanks.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// move the bareel the right amount this frame
	//given a max elevation speed and the frame time
	auto ElevationChange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegress, MaxElevationDegress);
	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
	UE_LOG(LogTemp, Warning, TEXT("%f Barrel Elevation Amount %f"), RawNewElevation, MaxElevationDegress)
}

