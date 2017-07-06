// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Most be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	 
public:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;

private:
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;
	float CrosshairYLocation = 0.3333;


	//Returns the tank possesed by the PlayerController
	ATank* GetControlledTank() const;

	//Guides the point which the tank's turret has to aim
	void AimTowardsCrosshair();

	//Returns if the aiming is point at some object
	//Returns the location of the point is aiming as a OUT parameter
	bool GetSightHitLocation( FVector& ) const;

	
	
};
