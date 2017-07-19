// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState :uint8
{
	Locked,
	Aiming,
	Reloading
};

//Forward Declaration
class UTankBarrel; 
class UTankTurret;

//Holds tank's properties and methods
UCLASS(meta=(BlueprintSpawnableComponent), ClassGroup = (Custom))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimingAt(FVector, float);

	//Called from tank class BP to set the barrel and turret meshes
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

private:
	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector);
	
protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;

};
