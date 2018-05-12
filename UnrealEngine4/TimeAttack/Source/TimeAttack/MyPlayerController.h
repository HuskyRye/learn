// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TimeAttackPawn.h"

#include "MyPlayerController.generated.h"

UCLASS()
class TIMEATTACK_API AMyPlayerController : public APlayerController {

    GENERATED_BODY()

public:
    AMyPlayerController();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    void StartGameSetup();
    void Restart();
    void UpdateLap();
    void RespawnVehicle();
    void StarRaceTime();
    void StopRaceTime();
    void StartLapTime();
    void StopLapTime();

protected:
    /** Time Attack Value Variable */
    int32 CurrentLap;
    int32 MaxLaps;
    float CurrentRaceTime;
    float CurrentLapTime;
    float GoldTime;
    float SilverTime;
    float BronzeTime;
    float BestLapTime;
    float BestRaceTime;
    float DefaultBestLapTime;
    float DefaultBestRaceTime;

    /** Time Attack Text Variable */
    FText RaceTimeText;
    FText CurrentLapText;
    FText MaxLapText;
    FText GoldTimeText;
    FText SilverTimeText;
    FText BronzeTimeText;
    FText BestRaceTimeText;
    FText BestLapTimeText;
    FText MapOfMap;
    FText ReadyText;

    bool RaceComplete;
    bool RaceStart;
    FTransform RespawnLocation;
    FString SaveSlot;

    // The widget class to use for our HUD screen
    TSubclassOf<UUserWidget> HUDWidgetClass;

    // The instance of the HUD
    UPROPERTY()
    UUserWidget* HUDReference;

    ATimeAttackPawn* VehicleReference;

private:
    void InitText();
    bool SaveGameCheck();
    void SaveTheGame();
    void LoadTheGame();
    void LapTimeCheck();
    void RaceTimeCheck();
    void UpdateGoals();
};
