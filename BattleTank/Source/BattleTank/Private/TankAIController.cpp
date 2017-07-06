// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	///Outputs the name of the tank possesed by the PlayerController
	auto PlayerTank = GetPlayerTank();

	///Pointer protection
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find PlayerTank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

//Returns the tank possesed by this AIPlayerController
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Returns the tank possesed by PlayerController
ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


