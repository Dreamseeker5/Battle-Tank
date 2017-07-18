// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//Pointer protection
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurning(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

	//Pointer protection
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw); 
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call SUPER because we're changing the funcionality

	//Makes the AI moves and allign according to the angular diference between
	//its forward vector and the one which points to the player tank
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntetion = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForwardDirection, AIForwardIntetion);
	auto RotateThrow = FVector::CrossProduct(TankForwardDirection, AIForwardIntetion);

	IntendMoveForward(ForwardThrow);
	IntendTurning(RotateThrow.Z);
	
	UE_LOG(LogTemp, Warning, TEXT("Forward: %f . Rotate: %f "), ForwardThrow, RotateThrow.Z);
}