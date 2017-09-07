// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class ROCKETTANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	
	// -1 is max downward speed and 1 is max up movement
	void Elevate(float RelativeSpeed);


private:
	
	UPROPERTY(EDITANYWHERE, Category = Setup)
	float MaxDegressPerSecond = 20.f;
	
	UPROPERTY(EDITANYWHERE, Category = Setup)
	float MinElevationDegress = 20.f;
	
	UPROPERTY(EDITANYWHERE, Category = Setup)
	float MaxElevationDegress = 70.f;

	
	
};
