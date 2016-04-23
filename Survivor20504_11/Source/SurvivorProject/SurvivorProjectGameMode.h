// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "DateTime.h"
#include "GameFramework/GameMode.h"
#include "SurvivorProjectGameMode.generated.h"

// enum for game states
UENUM(BlueprintType)
enum class ESurvivorPlayState
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ASurvivorProjectGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASurvivorProjectGameMode();

	virtual void Tick(float DeltaTime) override;

	/** Returns power needed to win - needed for the HUD */
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetPowerToWin() const;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category="Power")
	ESurvivorPlayState GetCurrentState() const;

	UFUNCTION(BlueprintCallable, Category = "State")
	void SetCurrentState(ESurvivorPlayState PlayState);

	UFUNCTION(BlueprintCallable, Category = "State")
		void SetKeyCollected(bool IsCollected);

	UFUNCTION(BlueprintCallable, Category = "State")
		void UpdateJokerPower(float Power);

	UFUNCTION(BlueprintCallable, Category = "State")
		bool GetKeyCollected();

	UFUNCTION(BlueprintCallable, Category = "State")
		float GetJokerPower();

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

private:
	ESurvivorPlayState CurrentState;

	bool KeyCollected;

	float JokerPower;

};



