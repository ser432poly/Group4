// Fill out your copyright notice in the Description page of Project Settings.

#include "SurvivorProject.h"
#include "BatteryPickup.h"


/** Set default value */
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);

	/** Base power level of battery*/
	BatteryPower = 150.0f;
}

void ABatteryPickup::WasCollected_Implementation()
{
	/** Use base pickup behaviour*/
	Super::WasCollected_Implementation();
	/** Destroy wire*/
	Destroy();
}

float ABatteryPickup::GetPower()
{
	return BatteryPower;
}
