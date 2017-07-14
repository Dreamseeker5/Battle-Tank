// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	//Force vector that'll be applied to the tank
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	//The location where the force is going to be applied (track's edges)
	auto ForceLocation = GetComponentLocation();
	//Getting the tank mesh
	//Downcast to a primitive component
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//Applying the force vector to the tank on a specific location of it
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



