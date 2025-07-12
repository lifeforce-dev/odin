// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ODNCircuitData.h"
#include "Engine/DeveloperSettingsBackedByCVars.h"
#include "ODNGameplayDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Gameplay, DefaultConfig, meta = (DisplayName = "Gameplay Settings"))
class WORKOUT_API UODNGameplayDeveloperSettings : public UDeveloperSettingsBackedByCVars
{
	GENERATED_BODY()
public:
	// UDeveloperSettingsBackedByCVars interface.
	virtual FName GetCategoryName() const override;
	// ~UDeveloperSettingsBackedByCVars interface.

	UFUNCTION()
	TSoftObjectPtr<UODNCircuitData> GetDefaultCircuitData() const { return CurrentCircuitData; } 

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Gameplay", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UODNCircuitData> CurrentCircuitData;
};
