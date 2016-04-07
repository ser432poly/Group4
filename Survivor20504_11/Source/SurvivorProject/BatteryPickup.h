// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVORPROJECT_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ABatteryPickup();

	/** Override the WasCollected function - implementation fucntion*/
	void WasCollected_Implementation() override;

	/** To access the wire power level*/
	float GetPower();

protected:
	/** Set the power emitted in the broken wire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float BatteryPower;
	
	
	
};
