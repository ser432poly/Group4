// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "Survior2050HUD.generated.h"

UCLASS()
class ASurvior2050HUD : public AHUD
{
	GENERATED_BODY()

public:
	ASurvior2050HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

