// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameMode.h"

void AFPSGameMode::StartPlay()
{
	Super::StartPlay(); // Calls base function

	// C Assert
	// If this fails throw an error
	check(GEngine != nullptr)
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Starting FPS Map")));

	// Log to console
	// int test = 10;
	// bool boolTest = true;
	// UE_LOG(LogTemp, Warning, TEXT("Starting FPS Map %i %d"), boolTest, test);

	// Shortcut to log to console
	// NOTE: This is new so there could be issues
	// UE_LOGFMT(LogTemp, Warning, "This is an int {TheInt}", ("TheInt", test));

	ChangeMenuWidget(UserWidgetPrefab);
}

void AFPSGameMode::ChangeMenuWidget(TSubclassOf<UFPSUserWidget> NewWidgetClass)
{
	// 1. If we have one, remove it
	if (CurrentWidget != nullptr) {
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	// 2. If we don't one, add it the viewport
	if (NewWidgetClass != nullptr) {
		CurrentWidget = CreateWidget<UFPSUserWidget>(GetWorld(), NewWidgetClass);
		CurrentWidget->AddToViewport();
	}
	
}
