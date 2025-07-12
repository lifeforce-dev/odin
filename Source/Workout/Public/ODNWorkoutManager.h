// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "ODNWorkoutManager.generated.h"

class UODNWorkoutItemData;
class UODNCircuitData;
class UODNWorkoutEvents;
class ODNWorkoutSession;
/**
 * 
 */
UCLASS(BlueprintType)
class WORKOUT_API UODNWorkoutManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	// UGameInstanceSubsystem impl
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	// ~UGameInstanceSubsystem impl

	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	UODNWorkoutSession* GetCurrentWorkoutSession() const;
	
	UFUNCTION(BlueprintPure, Category = "WorkoutManager")
	UODNWorkoutEvents* GetWorkoutEvents() const;
	
	UFUNCTION(BlueprintCallable, Category = "WorkoutManager")
	UODNWorkoutSession* CreateWorkoutSession();

	UFUNCTION(BlueprintCallable, Category = "WorkoutManager")
	void ResetWorkoutSession();

private:

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UODNWorkoutSession> CurrentSession = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UODNWorkoutEvents> WorkoutEvents = nullptr;
};
