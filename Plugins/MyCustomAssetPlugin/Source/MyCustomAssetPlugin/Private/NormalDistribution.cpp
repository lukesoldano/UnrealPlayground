// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalDistribution.h"

float UNormalDistribution::DrawSample()
{
   return std::normal_distribution<>(Mean, StandardDeviation)(RandomNumGenerator);
}

void UNormalDistribution::LogSample()
{
   UE_LOG(LogTemp, Log, TEXT("Sample: %f"), DrawSample());
}