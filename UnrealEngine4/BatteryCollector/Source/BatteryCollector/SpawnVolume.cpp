// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // Create the Box Component to represent the spawn volume
    WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
    RootComponent = (USceneComponent*)WhereToSpawn;

    // Set the spawn delay range
    SpawnDelayRangeLow = 0.5;
    SpawnDelayRangeHigh = 2.25;
}

FVector ASpawnVolume::GetRandomPointInVolume()
{
    FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
    FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;

    return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SetSpawningActive(bool bShouldSpawn)
{
    if (bShouldSpawn) {
        SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
        GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
    } else {
        GetWorldTimerManager().ClearTimer(SpawnTimer);
    }
}

void ASpawnVolume::SpawnPickup()
{
    if (WhatToSpawn != NULL) {
        UWorld* const World = GetWorld();
        if (World) {
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = this;
            SpawnParams.Instigator = Instigator;
            FVector SpawnLocation = GetRandomPointInVolume();
            FRotator SpawnRotation{
                FMath::FRand() * 360.0f,
                FMath::FRand() * 360.0f,
                FMath::FRand() * 360.0f
            };
            APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
            SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
            GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
        }
    }
}

