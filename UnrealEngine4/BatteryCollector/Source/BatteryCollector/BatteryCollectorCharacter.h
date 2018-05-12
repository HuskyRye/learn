// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "BatteryCollectorCharacter.generated.h"

UCLASS(config = Game)
class ABatteryCollectorCharacter : public ACharacter {

    GENERATED_BODY()

    /** Camera boom positioning the camera behind the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;

    /** Follow camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FollowCamera;

    /** Collection sphere */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
    class USphereComponent* CollectionSphere;

public:
    ABatteryCollectorCharacter();

    /** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    float BaseTurnRate;

    /** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    float BaseLookUpRate;

    /** Accessor function for innitial power */
    UFUNCTION(BlueprintPure, Category = "Power")
    float GetInitialPower() const;

    /** Accessor function for current power */
    UFUNCTION(BlueprintPure, Category = "Power")
    float GetCurrentPower() const;

    /**
    Function to update the character's power
    * @param PowerChange This is the amout to change the power by, and it can be positive or negative
    */
    void UpdatePower(float PowerChange);

protected:
    /** Resets HMD orientation in VR. */
    void OnResetVR();

    /** Called for forwards/backward input */
    void MoveForward(float Value);

    /** Called for side to side input */
    void MoveRight(float Value);

    /** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
    void TurnAtRate(float Rate);

    /**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
    void LookUpAtRate(float Rate);

    /** Handler for when a touch input begins. */
    void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

    /** Handler for when a touch input stops. */
    void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    // End of APawn interface

    // Called whe nwe press a key to collect any pickups inside the CollectionSphere
    void CollectPickups();

    // The starting power level of our character
    float InitialPower;

    // Multiplier for character speed
    float SpeedFactor;

    // Speed whe power level of the character is 0
    float BaseSpeed;

    UFUNCTION(BlueprintImplementableEvent, Category = "Power")
    void PowerChangeEffect();

private:
    // Current power level of our character
    float CharacterPower;

public:
    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
    /** Returns FollowCamera subobject **/
    FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
    /** Returns CollectionSphere subobject **/
    FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }
};
