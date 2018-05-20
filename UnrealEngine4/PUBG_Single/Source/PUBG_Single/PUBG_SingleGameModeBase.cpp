/*
    Author: 刘臣轩
    Date: 2018.5.17
*/

#include "PUBG_SingleGameModeBase.h"

#include "PUBG_Character.h"
#include "UObject/ConstructorHelpers.h"

APUBG_SingleGameModeBase::APUBG_SingleGameModeBase()
{
    /*
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_PUBG_Character"));
    if (PlayerPawnBPClass.Class)
        DefaultPawnClass = PlayerPawnBPClass.Class;
    */
    DefaultPawnClass = APUBG_Character::StaticClass();
}
