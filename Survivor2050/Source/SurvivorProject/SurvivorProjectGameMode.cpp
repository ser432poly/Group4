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

	PowerToWin = 2000;
}

void ASurvivorProjectGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

float ASurvivorProjectGameMode::GetPowerToWin() const
{
	return PowerToWin;
}

