// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameplayTagContainer.h"
#include "ODNWorkoutItemData.h"
#include "ODNGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WORKOUT_API AODNGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, Category="Config")
	TMap<FGameplayTag, TObjectPtr<UODNWorkoutItemData>> WorkoutDataMap;

	UPROPERTY(EditAnywhere, Category = "Workout Config")
	TArray<TObjectPtr<UODNWorkoutItemData>> WorkoutDataAssets;
};
