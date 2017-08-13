// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup the collision mesh

		//Set the collision mesh as a default component
		CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Projectile"));
		//Set the collision mesh as the root component
		SetRootComponent(CollisionMesh);
		//Activate as default the "Simulation Generates Hit Events" option in "Collision" category
		CollisionMesh->SetNotifyRigidBodyCollision(true);
		//Activate as default the "Visible" option in "Rendering" category
		CollisionMesh->SetVisibility(false);

	//Setup the particle system

		//Set the collision mesh as a default component
		LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
		//Attach the particle system component to the root component (Collision mesh)
		LaunchBlast->AttachTo(RootComponent);

	//Setup the projectile movement component
		//Set the collision mesh as a default component
		ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
		//Make the projectile unable to move after construction
		ProjectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Called from the tank class
void AProjectile::LaunchProjectile(float speed)
{
	auto Time = GetWorld()->GetTimeSeconds();

	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector*speed);

	//Activate projectile movement (Was deactivated in the constructor of this class)
	ProjectileMovement->Activate();

}

