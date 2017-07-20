 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Most be the last include


/**
* Responsible for helping the player aim
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	 
public:

	virtual void BeginPlay() override;
	virtual void Tick(float) override;

private:

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;


	//Guides the point which the tank's turret has to aim
	void AimTowardsCrosshair();

	//Returns if the aiming is point at some object
	//Returns the location of the point is aiming as a OUT parameter
	bool GetSightHitLocation( FVector& ) const;

	bool GetLookDirection(FVector2D, FVector&) const;

	bool GetLookVectorHitLocation(FVector, FVector&) const;

protected:

	//Event which takes place when the aiming component is found
	//"BlueprintImplementableEvent" doesn't require definition
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent * AimCompRef);
};
