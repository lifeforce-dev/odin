// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ODNWorkoutItemData.h"

#include "ODNExerciseState.generated.h"

class UODNWorkoutManager;
/**
 * 
 */
UCLASS()
class WORKOUT_API UODNExerciseState : public UObject
{
	GENERATED_BODY()

public:

	static UODNExerciseState* Create(UODNWorkoutManager* InManager,
		UODNWorkoutItemData* InWorkoutItemData);

	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	FGameplayTag GetWorkoutItemTag() const;

	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	int32 GetRequiredRepCount() const;
	
	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	int32 GetCurrentRepCount() const;

	// Returns whether we consider this exercise to be done.
	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	bool IsComplete() const;


private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="State", meta = (AllowPrivateAccess = "true"))
	int32 CurrentRepCount = 0;

	// Const data Init from data asset
	// Increments as the user finishes reps.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Const State", meta = (AllowPrivateAccess = "true"))
	int32 RequiredRepCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Const State", meta = (AllowPrivateAccess = "true"))
	FGameplayTag WorkoutItemTag;

	TObjectPtr<UODNWorkoutManager> WorkoutManager;
};
