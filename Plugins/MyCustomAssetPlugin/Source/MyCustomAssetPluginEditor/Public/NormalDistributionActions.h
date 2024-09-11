// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "NormalDistribution.h"

/**
 * 
 */
class MYCUSTOMASSETPLUGINEDITOR_API FNormalDistributionActions : public FAssetTypeActions_Base
{
public:

   UClass* GetSupportedClass() const override { return UNormalDistribution::StaticClass(); }
   FText GetName() const override { return INVTEXT("Normal Distribution"); }
   FColor GetTypeColor() const override { return FColor::Cyan; }
   uint32 GetCategories() override { return EAssetTypeCategories::Misc; }

   void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor) override;

};
