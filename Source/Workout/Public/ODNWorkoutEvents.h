// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "ODNWorkoutEvents.generated.h"

/**
 * 
 */
UCLASS()
class WORKOUT_API UODNWorkoutEvents : public UObject
{
	GENERATED_BODY()
public:
	// Triggered when a workout item button (ex. Lat Pulldown) is clicked
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExerciseStarted, FGameplayTag, WorkoutItemTag);

	// Triggered when the "Workout Button" is pressed if a workout is not already in progress.
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWorkoutStarted);

	// Triggered when the last exercise of a workout has been completed.
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWorkoutEnded);

	// Triggered when the workout button has been clicked, but today's workout is already done,
	// and a new session will not be started.
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWorkoutVisited);

	// Triggered when the workout button has been clicked, but a session is already in progress.
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWorkoutResumed);

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="WorkoutEvents")
	FExerciseStarted ExerciseStartedDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="WorkoutEvents")
	FWorkoutStarted WorkoutStartedDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="WorkoutEvents")
	FWorkoutStarted WorkoutEndedDelegate;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="WorkoutEvents")
	FWorkoutStarted WorkoutVisitedDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="WorkoutEvents")
	FWorkoutStarted WorkoutResumedDelegate;
};
