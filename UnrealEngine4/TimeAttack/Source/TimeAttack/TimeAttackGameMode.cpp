// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TimeAttackGameMode.h"

#include "TimeAttackHud.h"
#include "TimeAttackPawn.h"

ATimeAttackGameMode::ATimeAttackGameMode()
{
    DefaultPawnClass = ATimeAttackPawn::StaticClass();
    HUDClass = ATimeAttackHud::StaticClass();
}
