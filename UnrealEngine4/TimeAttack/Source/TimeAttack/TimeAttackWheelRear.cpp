// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TimeAttackWheelRear.h"

#include "TireConfig.h"
#include "UObject/ConstructorHelpers.h"

UTimeAttackWheelRear::UTimeAttackWheelRear()
{
    ShapeRadius = 18;
    ShapeWidth = 15;
    bAffectedByHandbrake = true;
    SteerAngle = 0;

    // Setup suspension forces
    SuspensionForceOffset = -4;
    SuspensionMaxRaise = 8;
    SuspensionMaxDrop = 12;
    SuspensionNaturalFrequency = 9;
    SuspensionDampingRatio = 1.05;

    // Find the tire object and set the data for it
    static ConstructorHelpers::FObjectFinder<UTireConfig> TireData(TEXT("/Game/VehicleAdv/Vehicle/WheelData/Vehicle_BackTireConfig.Vehicle_BackTireConfig"));
    TireConfig = TireData.Object;
}
