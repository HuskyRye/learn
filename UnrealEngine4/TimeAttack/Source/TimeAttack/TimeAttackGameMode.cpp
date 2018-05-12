// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TimeAttackGameMode.h"
#include "TimeAttackPawn.h"
#include "TimeAttackHud.h"

ATimeAttackGameMode::ATimeAttackGameMode()
{
	DefaultPawnClass = ATimeAttackPawn::StaticClass();
	HUDClass = ATimeAttackHud::StaticClass();
}
