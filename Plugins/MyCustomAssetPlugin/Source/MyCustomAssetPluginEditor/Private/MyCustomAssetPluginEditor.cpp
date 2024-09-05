// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyCustomAssetPluginEditor.h"

void FMyCustomAssetPluginEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
   NormalDistributionAssetTypeActions = MakeShared<FNormalDistributionActions>();
   FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(NormalDistributionAssetTypeActions.ToSharedRef());
}

void FMyCustomAssetPluginEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
   if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;
   FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(NormalDistributionAssetTypeActions.ToSharedRef());
}

IMPLEMENT_MODULE(FMyCustomAssetPluginEditorModule, MyCustomAssetPluginEditor)