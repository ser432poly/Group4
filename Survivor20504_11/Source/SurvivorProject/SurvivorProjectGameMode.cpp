// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SurvivorProject.h"
#include "SurvivorProjectGameMode.h"
#include "SurvivorProjectHUD.h"
#include "SurvivorProjectCharacter.h"
#include "Blueprint/UserWidget.h"

ASurvivorProjectGameMode::ASurvivorProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASurvivorProjectHUD::StaticClass();

	PowerToWin = 100;
}

void ASurvivorProjectGameMode::BeginPlay()
{
	Super::BeginPlay();
	SetCurrentState(ESurvivorPlayState::EPlaying);
	SetKeyCollected(false);
	SetLevel1Completed(false);
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void ASurvivorProjectGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Check that we are using the battery collector character
	ASurvivorProjectCharacter* MyCharacter = Cast<ASurvivorProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (MyCharacter)
	{
		// If our power is greater than needed to win, set the game's state to Won
		if (MyCharacter->GetCurrentGunPower() <= 0.0 || MyCharacter->GetCurrentCharacterPower() <= 0.0)
		{
			SetCurrentState(ESurvivorPlayState::EGameOver);
			// Destroy character when game over
			MyCharacter->Destroy();
		}
	}
		
}

float ASurvivorProjectGameMode::GetPowerToWin() const
{
	return PowerToWin;
}

ESurvivorPlayState ASurvivorProjectGameMode::GetCurrentState() const
{
	return CurrentState;
}

void ASurvivorProjectGameMode::SetCurrentState(ESurvivorPlayState PlayState)
{
	CurrentState = PlayState;
}

void ASurvivorProjectGameMode::SetKeyCollected(bool IsKeyCollected)
{
	KeyCollected = IsKeyCollected;
}

void ASurvivorProjectGameMode::SetLevel1Completed(bool IsLevel1Completed)
{
	Level1Completed = IsLevel1Completed;
}

bool ASurvivorProjectGameMode::GetKeyCollected()
{
	return KeyCollected;
}
bool ASurvivorProjectGameMode::GetLevel1Completed()
{
	return Level1Completed;
}