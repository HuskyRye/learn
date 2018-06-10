/*
    Author: 刘臣轩
    Date: 2018.5.29
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Animation/BlendSpace.h"
#include "Camera/CameraComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "PUBG_Character.generated.h"

UCLASS()
class PUBG_SINGLE_API APUBG_Character : public ACharacter {

    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    APUBG_Character();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    // Called every frame
    void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    // Called for forwards/backward input
    void MoveForward(float AxisValue);

    // Called for side to side input
    void MoveRight(float AxisValue);

    // Called when Sprint key is pressed
    void SprintPressed();

    // Called when Sprint key is released
    void SprintReleased();

    // Called when Freelook key is pressed
    void FreelookPressed();

    // Called when Freelook key is released
    void FreelookReleased();

    // Called when Walk key is pressed
    void WalkPressed();

    // Called when Walk key is released
    void WalkReleased();

private:
    // Movement component used for movement logic in various movement modes
    UCharacterMovementComponent* CharacterMovement;

    // Camera boom positioning the camera behind the character
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* SpringArm;

    // Follow camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FollowCamera;

    // Curve float reference
    UPROPERTY(VisibleAnywhere, Category = "PUBG", Meta = (AllowPrivateAccess = "true"))
    UCurveFloat* TurnBackCurve;
    
    // The timeline used to turn the Controller back
    FTimeline TurnBackTimeline;

    UFUNCTION()
    void UpdateController(float Value);

    FRotator TargetControlRotation;
    FRotator CurrentContrtolRotation;

public:
    FORCEINLINE USpringArmComponent* GetSpringArm() const { return SpringArm; }
    FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
