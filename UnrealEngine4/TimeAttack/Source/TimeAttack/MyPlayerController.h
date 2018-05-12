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
    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void StartGameSetup();

    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void Restart();

    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void UpdateLap();

    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void RespawnVehicle();

    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void StarRaceTime();

    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void StopRaceTime();

    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void StartLapTime();

    UFUNCTION(BlueprintCallable, Category = "TimeAttack")
    void StopLapTime();

protected:
    /** Time Attack Value Variable */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    int32 CurrentLap;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    int32 MaxLaps;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float CurrentRaceTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float CurrentLapTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float GoldTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float SilverTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float BronzeTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float BestLapTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float BestRaceTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float DefaultBestLapTime;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackValueVariable")
    float DefaultBestRaceTime;

    /** Time Attack Text Variable */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText RaceTimeText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText CurrentLapText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText MaxLapText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText GoldTimeText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText SilverTimeText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText BronzeTimeText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText BestRaceTimeText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText BestLapTimeText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText MapOfMap;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackTextVariable")
    FText ReadyText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackVariable")
    bool RaceComplete;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackVariable")
    bool RaceStart;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackVariable")
    FTransform RespawnLocation;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttackVariable")
    FString SaveSlot;

    // The widget class to use for our HUD screen
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TimeAttack")
    TSubclassOf<UUserWidget> HUDWidgetClass;

    // The instance of the HUD
    UPROPERTY()
    UUserWidget* HUDReference;

    UPROPERTY()
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
