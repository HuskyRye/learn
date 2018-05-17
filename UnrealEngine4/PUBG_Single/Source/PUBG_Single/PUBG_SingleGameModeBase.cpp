// Fill out your copyright notice in the Description page of Project Settings.

#include "PUBG_SingleGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

APUBG_SingleGameModeBase::APUBG_SingleGameModeBase()
{
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_PUBG_Character"));
    if (PlayerPawnBPClass.Class)
        DefaultPawnClass = PlayerPawnBPClass.Class;
}
