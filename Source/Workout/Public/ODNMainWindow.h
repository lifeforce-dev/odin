// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"

#include "ODNMainWindow.generated.h"

USTRUCT(BlueprintType)
struct FAppPageEntry
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag PageTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> WidgetClass;
};

/**
 * 
 */
UCLASS()
class WORKOUT_API UODNMainWindow : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "ODNMainWindow")
	void SetPage(FGameplayTag NewPage);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pages", meta = (AllowPrivateAccess = "true"))
	TArray<FAppPageEntry> PageDefinitions;
	
	UPROPERTY(meta = (AllowPrivateAccess))
	TMap<FGameplayTag, UUserWidget*> PageMap;
	
	UPROPERTY(meta = (AllowPrivateAccess))
	UUserWidget* CurrentPageWidget = nullptr;

	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	class UWidgetSwitcher* PageSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pages", meta = (AllowPrivateAccess = "true"))
	FGameplayTag DefaultPageTag;
};
