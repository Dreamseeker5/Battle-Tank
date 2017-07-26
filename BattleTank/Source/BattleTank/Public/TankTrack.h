// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetThrottle(float Throttle);

	//Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000; // Mass:4000 kg   Aceleration 10 m/s2

private:

	//Constructor
	UTankTrack();

	virtual void BeginPlay() override;	

	//Track the contact between floor and tracks
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	void ApplySidewaysForce();

	float CurrentThrottle = 0;

};
