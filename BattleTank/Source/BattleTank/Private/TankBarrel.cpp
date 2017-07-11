// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Clamping the relative speed so it maintains in the range of -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	//Calculate the amount of degrees that is going to move per frame
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond *GetWorld()->DeltaTimeSeconds;
	//Change barrel's elevation so is ready to be set 
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	//Clamp the barrel's elevation
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

