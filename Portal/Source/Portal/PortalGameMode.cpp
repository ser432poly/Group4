// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Portal.h"
#include "PortalGameMode.h"
#include "PortalHUD.h"
#include "PortalCharacter.h"

APortalGameMode::APortalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APortalHUD::StaticClass();
}
