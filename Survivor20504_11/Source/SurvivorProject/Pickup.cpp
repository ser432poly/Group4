// Fill out your copyright notice in the Description page of Project Settings.

#include "SurvivorProject.h"
#include "Pickup.h"



// Sets default values
APickup::APickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/** All pickups start active */
	bIsActive = true;

	/** Create the static mesh component */
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;

	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->AttachTo(RootComponent);
	CollectionSphere->SetSphereRadius(2.0f);


}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/** Return whether or not the pickup is active */
bool APickup::IsActive()
{
	return bIsActive;
}

/** Allows other classes to change whether pickup is active or not */
void APickup::SetActive(bool NewPickupState)
{
	bIsActive = NewPickupState;
}

void APickup::WasCollected_Implementation()
{
	/** Log a debug message*/
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("Collected %s"), *PickupDebugString);
}


/*AActor* APickup::GetPickups()
{
	// Get all overlapping Actors and store them in an array
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);
	return CollectedActors[0];
}*/