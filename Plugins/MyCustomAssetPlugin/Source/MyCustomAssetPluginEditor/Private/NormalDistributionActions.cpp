// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalDistributionActions.h"

#include "NormalDistributionEditorToolkit.h"

void FNormalDistributionActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
   MakeShared<FNormalDistributionEditorToolkit>()->InitEditor(InObjects);
}