// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCustomAssetFactory.h"
#include "NormalDistribution.h"

namespace
{
   constexpr TCHAR s_JSON_MEAN_KEY[] = TEXT("mean");
   constexpr TCHAR s_JSON_STD_DEV_KEY[] = TEXT("deviation");
}

UMyCustomAssetFactory::UMyCustomAssetFactory()
{
   Formats.Add("myasset;Normal Distribution");
   SupportedClass = UNormalDistribution::StaticClass();
   bCreateNew = false;
   bEditorImport = true;
}

UObject* UMyCustomAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
   return NewObject<UNormalDistribution>(InParent, Class, InName, Flags);
}

UObject* UMyCustomAssetFactory::FactoryCreateBinary(
   UClass* Class,
   UObject* InParent,
   FName Name,
   EObjectFlags Flags,
   UObject* Context,
   const TCHAR* Type,
   const uint8*& Buffer,
   const uint8* BufferEnd,
   FFeedbackContext* Warn)
{
   FEditorDelegates::OnAssetPreImport.Broadcast(this, Class, InParent, Name, Type);

   UNormalDistribution* NormalDistribution = nullptr;
   FString JsonContents;

   FFileHelper::BufferToString(JsonContents, Buffer, BufferEnd - Buffer);
   
   TSharedPtr<FJsonObject> JsonObject;
   if (!FJsonSerializer::Deserialize(TJsonReaderFactory<TCHAR>::Create(JsonContents), JsonObject) ||
       JsonObject == nullptr)
   {
      UE_LOG(LogTemp, Error, TEXT("Failed to deserialize myasset JSON file"));
      return nullptr;
   }

   NormalDistribution = NewObject<UNormalDistribution>(InParent, Class, Name, Flags);
   if (NormalDistribution)
   {
      NormalDistribution->Mean = JsonObject->GetNumberField(s_JSON_MEAN_KEY);
      NormalDistribution->StandardDeviation = JsonObject->GetNumberField(s_JSON_STD_DEV_KEY);
   }

   return NormalDistribution;
}