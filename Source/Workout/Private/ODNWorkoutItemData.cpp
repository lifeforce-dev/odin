// Fill out your copyright notice in the Description page of Project Settings.


#include "ODNWorkoutItemData.h"

FPrimaryAssetId UODNWorkoutItemData::GetPrimaryAssetId() const
{
	return FPrimaryAssetId("WorkoutItem", WorkoutItemTag.GetTagName());
}
