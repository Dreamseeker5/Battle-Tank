// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup the collision mesh
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Projectile"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName(""));
	LaunchBlast->AttachTo(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Launch Blast"));


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

