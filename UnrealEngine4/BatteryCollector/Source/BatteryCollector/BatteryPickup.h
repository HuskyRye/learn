/*
    Author:  Áõ³¼Ðù
    Date: 2018.5.12
*/

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 *
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup {

    GENERATED_BODY()

public:
    ABatteryPickup();

protected:
    void BeginPlay() override;

public:

    // Override the WasCollected function
    // - use Implementation because it's a BlueprintNativeEvent
    void wasCollected_Implementation() override;

    float getPower();

protected:
    // The amount of power the battery gives to the character
    float power;

};
