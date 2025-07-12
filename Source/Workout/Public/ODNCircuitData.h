// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"

#include "ODNCircuitData.generated.h"

class UODNWorkoutItemData;

USTRUCT(BlueprintType)
struct FWorkoutItemEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UODNWorkoutItemData> ItemData = nullptr;
};

/**
 * 
 */
UCLASS()
class WORKOUT_API UODNCircuitData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	TArray<FWorkoutItemEntry> WorkoutItems;
};
