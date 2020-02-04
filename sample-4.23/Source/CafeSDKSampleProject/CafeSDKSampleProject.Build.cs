// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class CafeSDKSampleProject : ModuleRules
{
	public CafeSDKSampleProject(ReadOnlyTargetRules Target) : base (Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CafeSDKPlugin" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		PrivatePCHHeaderFile = "CafeSDKSampleProject.h";
		
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
