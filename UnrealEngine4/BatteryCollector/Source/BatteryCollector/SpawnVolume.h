/*
    Author: 刘臣轩
    Date: 2018.5.12
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "Pickup.h"

#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor {

    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASpawnVolume();

    // Returns the WhereToSpawn subobject
    FORCEINLINE UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

    // Find a random point whithin the BoxComponent
    FVector GetRandomPointInVolume();

    void SetSpawningActive(bool bShouldSpawn);

protected:
    // The pickup to spawn
    UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<APickup> WhatToSpawn;

    FTimerHandle SpawnTimer;

    // Spawn delay
    float SpawnDelayRangeLow;
    float SpawnDelayRangeHigh;

private:
    // Box Component to specify where pickups should be spawned
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
    UBoxComponent* WhereToSpawn;

    // Handle spawning a new pickup
    void SpawnPickup();

    // The current spawn delay
    float SpawnDelay;
};
