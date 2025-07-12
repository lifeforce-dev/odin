// Fill out your copyright notice in the Description page of Project Settings.


#include "ODNGameMode.h"

#include "Logging/StructuredLog.h"

void AODNGameMode::BeginPlay()
{
	Super::BeginPlay();

	WorkoutDataMap.Empty();

	for (UODNWorkoutItemData* DataAsset: WorkoutDataAssets)
	{
		if (!IsValid(DataAsset))
			continue;

		FName TagName = DataAsset->GetPrimaryAssetId().PrimaryAssetName;
		FGameplayTag Tag = FGameplayTag::RequestGameplayTag(TagName);

		if (WorkoutDataMap.Contains(Tag))
		{
			UE_LOGFMT(LogTemp, Warning, "Duplicate tag in PrimaryAssetId: {0}", *Tag.ToString());
		}
		WorkoutDataMap.Add(Tag, DataAsset);
	}
}
