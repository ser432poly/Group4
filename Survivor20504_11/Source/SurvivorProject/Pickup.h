// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class SURVIVORPROJECT_API APickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/** Return the mesh for the pickup */
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	/** Return whether or not the pickup is active */
	UFUNCTION(BluePrintPure, Category = "Pickup")
		bool IsActive();

	/** Allows other classes to change whether pickup is active or not */
	UFUNCTION(BluePrintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);

	/** Function that is called when pickup is collected*/
	UFUNCTION(BluePrintNativeEvent)
		void WasCollected();

	virtual void WasCollected_Implementation();

	// static AActor* APickup::GetPickups();

protected:
	/** True when pickup can be used and false when deactivated */
	bool bIsActive;

private:
	/** Static Mesh to represent the pickup in the level*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollectionSphere;


};
