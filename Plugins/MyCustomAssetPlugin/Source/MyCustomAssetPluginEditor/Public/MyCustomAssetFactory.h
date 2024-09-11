// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MyCustomAssetFactory.generated.h"

/**
 * 
 */
UCLASS(hidecategories=Object)
class MYCUSTOMASSETPLUGINEDITOR_API UMyCustomAssetFactory : public UFactory
{
	GENERATED_BODY()

public:

   UMyCustomAssetFactory();

   // UFactory interface
   virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
   virtual UObject* FactoryCreateBinary(
      UClass* Class, 
      UObject* InParent, 
      FName Name, 
      EObjectFlags Flags, 
      UObject* Context, 
      const TCHAR* Type, 
      const uint8*& Buffer, 
      const uint8* BufferEnd, 
      FFeedbackContext* Warn) override;
   
   virtual bool ShouldShowInNewMenu() const override { return true; }
	
};
