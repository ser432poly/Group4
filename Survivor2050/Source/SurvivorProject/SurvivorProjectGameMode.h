// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "DateTime.h"
#include "GameFramework/GameMode.h"
#include "SurvivorProjectGameMode.generated.h"

UCLASS(minimalapi)
class ASurvivorProjectGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASurvivorProjectGameMode();

	/** Returns power needed to win - needed for the HUD */
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetPowerToWin() const;

	virtual void BeginPlay() override;

protected:
	/**The power needed to win the game */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float PowerToWin;

	/** The Widget class to use for our HUD screen */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	/** The instance of the HUD */
	UPROPERTY()
	class UUserWidget* CurrentWidget;
};



