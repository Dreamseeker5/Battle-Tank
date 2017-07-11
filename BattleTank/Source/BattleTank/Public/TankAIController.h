// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	//Sets the initial values
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Returns the tank possesed by this AIPlayerController
	ATank* GetControlledTank() const;

	//Returns the tank possesed by PlayerController
	ATank* GetPlayerTank() const;

	
	
};
