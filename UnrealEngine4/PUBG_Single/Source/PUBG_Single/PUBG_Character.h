// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
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


private:
    // Camera boom positioning the camera behind the character
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* SpringArm;

    // Follow camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FollowCamera;

public:
    FORCEINLINE USpringArmComponent* GetSpringArm() const { return SpringArm; }
    FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
