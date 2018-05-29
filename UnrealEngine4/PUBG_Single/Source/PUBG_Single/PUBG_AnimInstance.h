/*
    Author: Áõ³¼Ðù
    Date: 2018.5.29
*/

#pragma once

#include "CoreMinimal.h"

#include "Animation/AnimInstance.h"

#include "PUBG_AnimInstance.generated.h"

UCLASS()
class PUBG_SINGLE_API UPUBG_AnimInstance : public UAnimInstance {

    GENERATED_BODY()

public:
    // Native update override point.
    void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
    // Current Speed of the character
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PUBG")
    float Speed;

    // The direction of the character's movement, from -180 to 180.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PUBG")
    float Direction;

    // Default AimOffset Yaw Value
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PUBG")
    float Yaw;

    // Default AimOffset Pitch Value
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PUBG")
    float Pitch;
};
