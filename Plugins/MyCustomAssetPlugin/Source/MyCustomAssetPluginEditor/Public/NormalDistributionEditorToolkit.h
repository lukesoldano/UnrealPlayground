// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NormalDistribution.h"
#include "Toolkits/AssetEditorToolkit.h"

/**
 * 
 */
class MYCUSTOMASSETPLUGINEDITOR_API FNormalDistributionEditorToolkit : public FAssetEditorToolkit
{
   UNormalDistribution* NormalDistribution;

public:

   void InitEditor(const TArray<UObject*>& InObjects);

   void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
   void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

   FName GetToolkitFName() const override { return FName("NormalDistributionEditor"); }
   FText GetBaseToolkitName() const override { return INVTEXT("NormalDistributionEditor"); }
   FString GetWorldCentricTabPrefix() const override { return "Normal Distribution"; }
   FLinearColor GetWorldCentricTabColorScale() const override { return {}; }

   float GetMean() const;
   void SetMean(float NewMean);

   float GetStandardDeviation() const;
   void SetStandardDeviation(float NewStandardDeviation);

};
