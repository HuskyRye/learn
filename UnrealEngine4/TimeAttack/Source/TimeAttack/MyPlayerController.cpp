// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"

AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = false;

    CurrentLap = 1;
    MaxLaps = 3;

    static ConstructorHelpers::FClassFinder<UUserWidget> HUDWidget(TEXT("/Game/Blueprints/UI/TimeAttack_HUD"));
    if (HUDWidget.Class)
        HUDWidgetClass = HUDWidget.Class;
}

void AMyPlayerController::BeginPlay()
{
    if (HUDWidgetClass) {
        HUDReference = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
        if (HUDReference)
            HUDReference->AddToViewport();
    }

    VehicleReference = Cast<ATimeAttackPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AMyPlayerController::startGameSetup()
{
}

void AMyPlayerController::restart()
{
}

void AMyPlayerController::updateLap()
{
}

void AMyPlayerController::respawnVehicle()
{
}

void AMyPlayerController::starRaceTime()
{
}

void AMyPlayerController::stopRaceTime()
{
}

void AMyPlayerController::startLapTime()
{
}

void AMyPlayerController::stopLapTime()
{
}

void AMyPlayerController::initText()
{
}

bool AMyPlayerController::saveGameCheck()
{
    return false;
}

void AMyPlayerController::saveTheGame()
{
}

void AMyPlayerController::loadTheGame()
{
}

void AMyPlayerController::lapTimeCheck()
{
}

void AMyPlayerController::raceTimeCheck()
{
}

void AMyPlayerController::updateGoals()
{
}
