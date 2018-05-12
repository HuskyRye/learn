// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "SpawnVolume.h"

#include "BatteryCollectorGameMode.generated.h"

UENUM(BlueprintType)
enum class EBatteryPlayState : uint8 {
    EPlaying,
    EGameOver,
    EWon,
    EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase {

    GENERATED_BODY()

public:
    ABatteryCollectorGameMode();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    // Called every frame
    void Tick(float DeltaTime) override;

    // Returns the power needed to win
    UFUNCTION(BlueprintPure, Category = "Power")
    float GetPowerToWin() const;

    UFUNCTION(BlueprintPure, Category = "Power")
    EBatteryPlayState GetCurrentState() const;

    void SetCurrentState(EBatteryPlayState NewState);

protected:
    // The rate at which the character loses power
    float DecayRate;

    // The power needed to win the game
    float PowerToWin;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
    TSubclassOf<UUserWidget> HUDWidgetClass;

    UPROPERTY()
    UUserWidget* CurrentWidget;

private:
    EBatteryPlayState CurrentState;

    TArray<ASpawnVolume*> SpawnVolumeActors;

    void HandleNewState(EBatteryPlayState NewState);
};
