/*
    Author: Áõ³¼Ðù
    Date: 2018.5.29
*/

#include "PUBG_AnimInstance.h"

void UPUBG_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    APawn* Pawn = TryGetPawnOwner();
    if (Pawn) {
        FVector Velocity = Pawn->GetVelocity();
        FRotator ActorRotation = Pawn->GetActorRotation();
        FRotator ControlRotation = Pawn->GetControlRotation();

        // PUBG_Blendspace
        Speed = Velocity.Size();
        Direction = CalculateDirection(Velocity, ActorRotation);

        // DefaultAimOffset
        FRotator DeltaRotation = ControlRotation - ActorRotation;
        Yaw = FMath::ClampAngle(DeltaRotation.Yaw, -90, 90);
        Pitch = FMath::ClampAngle(DeltaRotation.Pitch, -90, 90);
    }
}
