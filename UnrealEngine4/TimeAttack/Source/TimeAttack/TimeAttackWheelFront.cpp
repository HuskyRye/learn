// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TimeAttackWheelFront.h"
#include "TireConfig.h"
#include "UObject/ConstructorHelpers.h"

UTimeAttackWheelFront::UTimeAttackWheelFront()
{
    ShapeRadius = 18;
    ShapeWidth = 15;
    bAffectedByHandbrake = false;
    SteerAngle = 40;

    // Setup suspension forces
    SuspensionForceOffset = -4;
    SuspensionMaxRaise = 8;
    SuspensionMaxDrop = 12;
    SuspensionNaturalFrequency = 9;
    SuspensionDampingRatio = 1.05;

    // Find the tire object and set the data for it
    static ConstructorHelpers::FObjectFinder<UTireConfig> TireData(TEXT("/Game/VehicleAdv/Vehicle/WheelData/Vehicle_FrontTireConfig.Vehicle_FrontTireConfig"));
    TireConfig = TireData.Object;
}
