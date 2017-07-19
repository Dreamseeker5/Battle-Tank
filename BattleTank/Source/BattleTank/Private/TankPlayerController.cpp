// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Look for the tank's aiming component directly and passes a component's instance to the BP event method
	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
		//Pointer protection
		if (!AimingComponent)
		{
			FoundAimingComponent(AimingComponent);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerController can`t find AIMING COMPONENT at Begin Play"));
		}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	///Pointer protection
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out parameter

	if (GetSightHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightHitLocation(FVector &OutHitLocation) const
{
	///Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);

	///Deproject the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}	

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLocation; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection* LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false;
}
