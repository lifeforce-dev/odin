// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "ODNWorkoutSession.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogODNWorkoutSession, Log, All);

class UODNExerciseState;
class UODNWorkoutItemData;
class UODNWorkoutManager;
/**
 * 
 */
UCLASS(BlueprintType)
class WORKOUT_API UODNWorkoutSession : public UObject
{
	GENERATED_BODY()
public:

	static UODNWorkoutSession* Create(UODNWorkoutManager* InManager);

	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	UODNCircuitData* GetCurrentCircuitData() const;

	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	UODNWorkoutItemData* GetWorkoutItemDataForTag(const FGameplayTag& InWorkoutItemTag) const;
	
	UFUNCTION(BlueprintCallable, Category = "WorkoutSession")
	FDateTime GetStartTime() const { return StartTime; }

private:
	UFUNCTION()
	void OnExerciseStarted(FGameplayTag InWorkoutItemTag);

private:

	UPROPERTY(BlueprintReadOnly, Category = "WorkoutSession", meta = (AllowPrivateAccess = "true"))
	FDateTime StartTime = FDateTime::UtcNow();

	// TODO: Store the next-run circuit in save file.
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UODNCircuitData> CircuitData = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="WorkoutSession", meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<UODNExerciseState>> WorkoutItemStates;

	TObjectPtr<UODNWorkoutManager> WorkoutManager;
};
