// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"

#include "BatteryCollectorCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class)
        DefaultPawnClass = PlayerPawnBPClass.Class;

    static ConstructorHelpers::FClassFinder<UUserWidget> HUDWidget(TEXT("/Game/Blueprints/BatteryHUD"));
    if (HUDWidget.Class)
        HUDWidgetClass = HUDWidget.Class;

    DecayRate = 0.05;
}

void ABatteryCollectorGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (HUDWidgetClass) {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
        if (CurrentWidget)
            CurrentWidget->AddToViewport();
    }

    // Find all the spawn volume actors
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);
    for (AActor* Actor : FoundActors) {
        ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
        if (SpawnVolumeActor) {
            SpawnVolumeActors.AddUnique(SpawnVolumeActor);
        }
    }

    SetCurrentState(EBatteryPlayState::EPlaying);

    // Set the score to beat
    ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
    if (MyCharacter)
        PowerToWin = MyCharacter->GetInitialPower() * 1.25f;
}

void ABatteryCollectorGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
    if (MyCharacter) {
        float CurrentPower = MyCharacter->GetCurrentPower();
        if (CurrentPower > PowerToWin)
            SetCurrentState(EBatteryPlayState::EWon);
        else if (CurrentPower > 0)
            MyCharacter->UpdatePower(-DeltaTime * DecayRate * (MyCharacter->GetInitialPower()));
        else
            SetCurrentState(EBatteryPlayState::EGameOver);
    }
}

float ABatteryCollectorGameMode::GetPowerToWin() const
{
    return PowerToWin;
}

EBatteryPlayState ABatteryCollectorGameMode::GetCurrentState() const
{
    return CurrentState;
}

void ABatteryCollectorGameMode::SetCurrentState(EBatteryPlayState NewState)
{
    CurrentState = NewState;
    HandleNewState(CurrentState);
}

void ABatteryCollectorGameMode::HandleNewState(EBatteryPlayState NewState)
{
    switch (NewState) {
    case EBatteryPlayState::EPlaying: {
        for (ASpawnVolume* SpawnVolume : SpawnVolumeActors)
            SpawnVolume->SetSpawningActive(true);
    } break;
    case EBatteryPlayState::EGameOver: {
        for (ASpawnVolume* SpawnVolume : SpawnVolumeActors)
            SpawnVolume->SetSpawningActive(false);
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (PlayerController)
            PlayerController->SetCinematicMode(true, false, false, true, true);
        ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
        if (MyCharacter) {
            MyCharacter->GetMesh()->SetSimulatePhysics(true);
            MyCharacter->GetMovementComponent()->MovementState.bCanJump = false;
        }
    } break;
    case EBatteryPlayState::EWon: {
        for (ASpawnVolume* SpawnVolume : SpawnVolumeActors)
            SpawnVolume->SetSpawningActive(false);
    } break;
    case EBatteryPlayState::EUnknown:
        break;
    default:
        break;
    }
}