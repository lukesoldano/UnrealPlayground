// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "NormalDistributionActions.h"

// Following along from https://dev.epicgames.com/community/learning/tutorials/vyKB/unreal-engine-creating-a-custom-asset-type-with-its-own-editor-in-c
class FMyCustomAssetPluginEditorModule : public IModuleInterface
{
   TSharedPtr<FNormalDistributionActions> NormalDistributionAssetTypeActions;

public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

};
