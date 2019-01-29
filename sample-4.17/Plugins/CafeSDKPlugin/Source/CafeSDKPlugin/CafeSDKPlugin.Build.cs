// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

namespace UnrealBuildTool.Rules
{
	public class CafeSDKPlugin : ModuleRules
	{
		private string ThirdPartyPath
        {
            get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdPartyFrameworks/")); }
        }

		public CafeSDKPlugin (ReadOnlyTargetRules Target) : base (Target)
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
						"../../ThirdPartyFrameworks/iOS/NaverCafeSDK.embeddedframework.zip",
						"Resources/NaverCafeSDK.bundle"
                    )
                );
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
						"NaverLogin",
						"../../ThirdPartyFrameworks/iOS/NaverLogin.embeddedframework.zip",
						"Resources/NaverAuth.bundle"
                    )
                );
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
						"AFNetworking",
						"../../ThirdPartyFrameworks/iOS/AFNetworking.embeddedframework.zip"
                    )
                );
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
                        "SDWebImage",
                        "../../ThirdPartyFrameworks/iOS/SDWebImage.embeddedframework.zip"
                    )
                );
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
                        "FLAnimatedImage",
                        "../../ThirdPartyFrameworks/iOS/FLAnimatedImage.embeddedframework.zip"
                    )
                );
                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
                        "ApiGateway",
                        "../../ThirdPartyFrameworks/iOS/ApiGateway.embeddedframework.zip"
                    )
                );
				PublicAdditionalFrameworks.Add(
					new UEBuildFramework(
					"openssl",
					"../../ThirdPartyFrameworks/iOS/openssl.embeddedframework.zip"
					)
				);

		bEnableObjCExceptions = false;
                PublicFrameworks.AddRange(
                    new string[] {
						"UIKit",
						"Foundation",
						"MediaPlayer",
						"SystemConfiguration",
						"Security",
						"MobileCoreServices",
						"GameKit",
                        "AssetsLibrary",
                        "WebKit",
                        "ReplayKit"
                    }
                );
                PublicWeakFrameworks.Add("ReplayKit");
            }

            if (Target.Platform == UnrealTargetPlatform.Android)
            {

                string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "CafeSDKPlugin_APL.xml"));
            }

		}
	}
}
