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
    void startGameSetup();
    void restart();
    void updateLap();
    void respawnVehicle();
    void starRaceTime();
    void stopRaceTime();
    void startLapTime();
    void stopLapTime();

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

    TSubclassOf<UUserWidget> HUDWidgetClass;

    UPROPERTY()
    UUserWidget* HUDReference;

    ATimeAttackPawn* VehicleReference;

private:
    void initText();
    bool saveGameCheck();
    void saveTheGame();
    void loadTheGame();
    void lapTimeCheck();
    void raceTimeCheck();
    void updateGoals();
};
