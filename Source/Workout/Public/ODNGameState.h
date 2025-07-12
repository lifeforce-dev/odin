// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"

#include "ODNGameState.generated.h"

/**
 * 
 */

// Checks which circuit to use
// Loads the list of ActionItemStates for that circuit
// Begins state tracking according to user interaction
UCLASS()
class WORKOUT_API AODNGameState : public AGameState
{
	GENERATED_BODY()
};
