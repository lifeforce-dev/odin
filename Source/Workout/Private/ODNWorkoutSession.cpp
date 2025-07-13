// Fill out your copyright notice in the Description page of Project Settings.


#include "ODNWorkoutSession.h"

#include "GameplayTagsManager.h"
#include "ODNGameplayDeveloperSettings.h"
#include "ODNExerciseState.h"
#include "ODNWorkoutEvents.h"
#include "ODNWorkoutItemData.h"
#include "ODNWorkoutManager.h"
#include "Algo/AnyOf.h"

#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"

DEFINE_LOG_CATEGORY(LogODNWorkoutSession);


UODNWorkoutSession* UODNWorkoutSession::Create(UODNWorkoutManager* InManager)
{
	ensure(IsValid(InManager));

	auto* Session = NewObject<UODNWorkoutSession>(InManager);
	if (UODNWorkoutEvents* Events = InManager->GetWorkoutEvents())
	{
		Events->ExerciseStartedDelegate.AddDynamic(Session,
			&UODNWorkoutSession::OnExerciseStarted);
	}
	Session->WorkoutManager = InManager;
	auto GameplayDeveloperSettings = GetMutableDefault<UODNGameplayDeveloperSettings>();
	Session->CircuitData = GameplayDeveloperSettings->GetDefaultCircuitData().LoadSynchronous();

	return Session;
}

UODNCircuitData* UODNWorkoutSession::GetCurrentCircuitData() const
{
	return CircuitData;
}

UODNWorkoutItemData* UODNWorkoutSession::GetWorkoutItemDataForTag(const FGameplayTag& InWorkoutItemTag) const
{
	if (!InWorkoutItemTag.IsValid())
	{
		return nullptr;
	}
	if (!CircuitData || !InWorkoutItemTag.IsValid())
	{
		return nullptr;
	}

	const FWorkoutItemEntry* Entry = Algo::FindBy(CircuitData->WorkoutItems,
		InWorkoutItemTag,
		&FWorkoutItemEntry::Tag);

	ensure(Entry);

	return Entry ? Entry->ItemData.Get() : nullptr;
}

void UODNWorkoutSession::OnExerciseStarted(FGameplayTag InWorkoutItemTag)
{
	if (!ensure(InWorkoutItemTag.IsValid()))
	{
		UE_LOGFMT(LogTemp, Warning,
				  "OnExerciseStarted called with INVALID tag. tag={0}", *InWorkoutItemTag.ToString());
		return;
	}

	UE_LOGFMT(LogTemp, Display, "Exercise started. tag={0}", *InWorkoutItemTag.ToString());

	bool bExists = !WorkoutItemStates.IsEmpty() && Algo::AnyOf(WorkoutItemStates,
		[InWorkoutItemTag](const UODNExerciseState* InWorkoutItemState)
	{
		return InWorkoutItemState && InWorkoutItemState->GetWorkoutItemTag() == InWorkoutItemTag;
	});

	// We already have this one, its state is accessible and there's nothing for us to do.
	if (bExists)
	{
		return;
	}

	// We need to create the exercise state.
	int32 Index = WorkoutItemStates.Add(UODNExerciseState::Create(WorkoutManager,
		GetWorkoutItemDataForTag(InWorkoutItemTag)));
}
