// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <random>
#include "NormalDistribution.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYCUSTOMASSETPLUGIN_API UNormalDistribution : public UObject
{
	GENERATED_BODY()

	std::mt19937 RandomNumGenerator;
	
public: 

	UNormalDistribution() :
      Mean(0.5f),
      StandardDeviation(0.2f) {}

	UPROPERTY(EditAnywhere)
   float Mean;

	UPROPERTY(EditAnywhere)
	float StandardDeviation;

	UFUNCTION(BlueprintCallable)
	float DrawSample();

	UFUNCTION(CallInEditor)
	void LogSample();

};
