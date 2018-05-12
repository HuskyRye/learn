/*
    Author:  Áõ³¼Ðù
    Date: 2018.5.12
*/

#include "BatteryPickup.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ABatteryPickup::ABatteryPickup()
{
    GetMesh()->SetSimulatePhysics(true);
    power = 150;
}

void ABatteryPickup::BeginPlay()
{
    Super::BeginPlay();
}

void ABatteryPickup::wasCollected_Implementation()
{
    Super::wasCollected_Implementation();
    Destroy();
}

float ABatteryPickup::getPower()
{
    return power;
}