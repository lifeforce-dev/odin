// Fill out your copyright notice in the Description page of Project Settings.


#include "ODNMainWindow.h"

#include "Components/WidgetSwitcher.h"

void UODNMainWindow::NativeConstruct()
{
	Super::NativeConstruct();
	for (const FAppPageEntry& Entry : PageDefinitions)
	{
		if (!Entry.WidgetClass) continue;

		UUserWidget* PageWidget = CreateWidget<UUserWidget>(GetWorld(), Entry.WidgetClass);
		PageMap.Add(Entry.PageTag, PageWidget);
		PageSwitcher->AddChild(PageWidget);
	}

	if (DefaultPageTag.IsValid())
	{
		SetPage(DefaultPageTag);
	}
}

void UODNMainWindow::SetPage(FGameplayTag NewPage)
{
	if (CurrentPageWidget)
	{
		CurrentPageWidget->RemoveFromParent();
		CurrentPageWidget = nullptr;
	}

	if (auto Found = PageMap.Find(NewPage))
	{
		if (UUserWidget* PageWidget = *Found)
		{
			int32 PageIndex = PageSwitcher->GetChildIndex(PageWidget);
			if (PageIndex != INDEX_NONE)
			{
				PageSwitcher->SetActiveWidgetIndex(PageIndex);
				CurrentPageWidget = PageWidget;
			}
		}
	}
}
