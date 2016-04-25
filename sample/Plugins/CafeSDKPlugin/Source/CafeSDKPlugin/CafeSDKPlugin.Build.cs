// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.


namespace UnrealBuildTool.Rules
{
	public class CafeSDKPlugin : ModuleRules
	{
		
		public CafeSDKPlugin (TargetInfo Target)
		{
			
			PublicIncludePaths.AddRange(
                new string[] {
                    "CafeSDKPlugin/Public"
                    // ... add public include paths required here ...
                }
			);
			
			PrivateIncludePaths.AddRange(
                new string[] {
                    "CafeSDKPlugin/Private"
                    // ... add other private include paths required here ...
                }
			);

			PublicDependencyModuleNames.AddRange(
                new string[] {
                    "Engine",
                    "Core",
                    "CoreUObject",
                    "Slate",
                    "SlateCore",
                    "UMG"
                }
			);

            PrivateDependencyModuleNames.AddRange(
                new string[] {
                    // ... add private dependencies that you statically link with here ...
                }
            );

            DynamicallyLoadedModuleNames.AddRange(
                new string[] {
                    // ... add any modules that your module loads dynamically here ...
                }
            );

            if (Target.Platform == UnrealTargetPlatform.IOS)
            {
                // Add framework
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
						"NaverCafeSDK",
						"../../iOS/ThirdPartyFrameworks/NaverCafeSDK.embeddedframework.zip",
						"Resources/NaverCafeSDK.bundle"
                    )
                );
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
						"NaverLogin",
						"../../iOS/ThirdPartyFrameworks/NaverLogin.embeddedframework.zip",
						"Resources/NaverAuth.bundle"
                    )
                );
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
						"AFNetworking",
						"../../iOS/ThirdPartyFrameworks/AFNetworking.embeddedframework.zip"
                    )
                );

                PublicFrameworks.AddRange(
                    new string[] {
						"UIKit",
						"Foundation",
						"MediaPlayer",
						"SystemConfiguration",
						"Security",
						"MobileCoreServices",
						"GameKit",
                    }
                );
            }

		}
	}
}
