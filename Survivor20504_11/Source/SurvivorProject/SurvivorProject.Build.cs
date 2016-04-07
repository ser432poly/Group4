// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SurvivorProject : ModuleRules
{
	public SurvivorProject(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });
        PublicDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
    }
}
