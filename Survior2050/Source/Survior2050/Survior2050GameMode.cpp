// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Survior2050.h"
#include "Survior2050GameMode.h"
#include "Survior2050HUD.h"
#include "Survior2050Character.h"

ASurvior2050GameMode::ASurvior2050GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASurvior2050HUD::StaticClass();
}
