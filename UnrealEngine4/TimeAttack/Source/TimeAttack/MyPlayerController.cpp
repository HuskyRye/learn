// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = false;
    
    CurrentLap = 1;
    MaxLaps = 3;
}

void AMyPlayerController::BeginPlay()
{
    if (HUDWidgetClass) {
        HUDReference = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
        if (HUDReference) {
            HUDReference->AddToViewport();
        }
    }
    VehicleReference = Cast<ATimeAttackPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}


void AMyPlayerController::StartGameSetup()
{

}

void AMyPlayerController::Restart()
{
}

void AMyPlayerController::UpdateLap()
{
}

void AMyPlayerController::RespawnVehicle()
{
}

void AMyPlayerController::StarRaceTime()
{

}

void AMyPlayerController::StopRaceTime()
{

}

void AMyPlayerController::StartLapTime()
{

}

void AMyPlayerController::StopLapTime()
{

}

void AMyPlayerController::InitText()
{

}

bool AMyPlayerController::SaveGameCheck()
{
    return false;
}

void AMyPlayerController::SaveTheGame()
{
}

void AMyPlayerController::LoadTheGame()
{
}

void AMyPlayerController::LapTimeCheck()
{
}

void AMyPlayerController::RaceTimeCheck()
{

}

void AMyPlayerController::UpdateGoals()
{

}
