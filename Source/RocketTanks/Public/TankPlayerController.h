// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// must be last include

//forward declrations

class ATank;

/**
 * 
 */
UCLASS()
class ROCKETTANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank*  GetControlledTank() const;


	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would hit where the crosshair intersects with the world
	void AimTowardCrossHair();

	
	//return out param true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EDITANYWHERE)
	float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EDITANYWHERE)
	float CrossHairYLocation = 0.33333333333f;

	UPROPERTY(EDITANYWHERE)
	float LineTraceRange = 100000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
};
