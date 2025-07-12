// Fill out your copyright notice in the Description page of Project Settings.

#include "ODNExerciseState.h"

#include "ODNWorkoutManager.h"

UODNExerciseState* UODNExerciseState::Create(UODNWorkoutManager* InManager,
	UODNWorkoutItemData* InWorkoutItemData)
{
	auto* State = NewObject<UODNExerciseState>(InManager);
	if (IsValid(InManager))
	{
		State->WorkoutManager = InManager;
		State->RequiredRepCount = InWorkoutItemData->RepCount;
		State->WorkoutItemTag = InWorkoutItemData->WorkoutItemTag;
	}

	return State;
}

FGameplayTag UODNExerciseState::GetWorkoutItemTag() const
{
	return WorkoutItemTag;
}

int32 UODNExerciseState::GetRequiredRepCount() const
{
	return RequiredRepCount;
}

int32 UODNExerciseState::GetCurrentRepCount() const
{
	return CurrentRepCount;
}

bool UODNExerciseState::IsComplete() const
{
	// TODO: Naively I think we can say its complete if we have reached our
	// rep count but with saves and loads it might be more complicated than that.
	return CurrentRepCount >= RequiredRepCount;
}
