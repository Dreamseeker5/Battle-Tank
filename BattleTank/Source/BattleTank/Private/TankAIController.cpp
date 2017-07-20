// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

//Sets the initial values
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	//Aims to the tank possesed by the PlayerController
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	{
		//Move the AI tanks towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimingAt(PlayerTank->GetActorLocation());

		
		//Fire at a uniform rate
		AimingComponent->Fire();
	}
}




