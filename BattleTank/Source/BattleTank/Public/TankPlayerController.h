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

private:
	//Returns the tank possesed by the PlayerController
	ATank* GetControlledTank() const;


	
	
};