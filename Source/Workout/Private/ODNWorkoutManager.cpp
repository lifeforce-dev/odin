// Fill out your copyright notice in the Description page of Project Settings.


#include "ODNWorkoutManager.h"

#include "Algo/Find.h"
#include "ODNWorkoutSession.h"
#include "ODNWorkoutEvents.h"
#include "Logging/StructuredLog.h"


void UODNWorkoutManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	WorkoutEvents = NewObject<UODNWorkoutEvents>(this);
}

UODNWorkoutSession* UODNWorkoutManager::GetCurrentWorkoutSession() const
{
	return CurrentSession;
}

UODNWorkoutEvents* UODNWorkoutManager::GetWorkoutEvents() const
{
	return WorkoutEvents;
}

UODNWorkoutSession* UODNWorkoutManager::CreateWorkoutSession()
{
	CurrentSession = UODNWorkoutSession::Create(this);

	UE_LOGFMT(LogTemp, Display, "Workout session started at {0}",
		CurrentSession->GetStartTime().ToIso8601());

	return CurrentSession;
}

void UODNWorkoutManager::ResetWorkoutSession()
{
	if (CurrentSession)
	{
		// TODO: log something useful here.
		// UE_LOGFMT(LogTemp, Display, "Ending workout session (completed {0} exercises)",
		// 	CurrentSession->GetCurrentRepCount());
		CurrentSession = nullptr;
	}
}
