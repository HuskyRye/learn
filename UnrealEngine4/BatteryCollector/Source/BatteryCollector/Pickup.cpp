/*
    Author: 刘臣轩
    Date: 2018.5.12
*/

#include "Pickup.h"

APickup::APickup()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // All pickups start active
    activity = true;

    // Create the static mesh component
    PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
    RootComponent = (USceneComponent*)PickupMesh;

}

// Returns active state
bool APickup::isActive()
{
    return activity;
}

// Change active state
void APickup::setActive(bool newstate)
{
    activity = newstate;
}

void APickup::wasCollected_Implementation()
{
    // Log a debug message
    FString PickupDebugString = GetName();
    UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
}

