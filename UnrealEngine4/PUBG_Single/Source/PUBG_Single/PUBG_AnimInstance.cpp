/*
    Author: Áõ³¼Ðù
    Date: 2018.5.21
*/

#include "PUBG_AnimInstance.h"

void UPUBG_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    APawn* Pawn = TryGetPawnOwner();
    if (Pawn) {
        FVector Velocity = Pawn->GetVelocity();
        Speed = Velocity.Size();
        Direction = CalculateDirection(Velocity, Pawn->GetActorRotation());
    }
}
