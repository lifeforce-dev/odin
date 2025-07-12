// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"

#include "ODNWorkoutItemData.generated.h"

/**
 * 
 */
UCLASS()
class WORKOUT_API UODNWorkoutItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	FName DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	int32 RepCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	int32 TimeInSeconds = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	FGameplayTag WorkoutItemTag;
};
