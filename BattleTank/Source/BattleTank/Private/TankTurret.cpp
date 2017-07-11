// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//Clamping the relative speed so it maintains in the range of -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	//Calculate the amount of degrees that is going to move per frame
	auto RotationChange = RelativeSpeed * MaxDegreePerSecond *GetWorld()->DeltaTimeSeconds;
	//Change turret's rotation so is ready to be set 
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
}


