// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"

#include "Checkpoint.generated.h"

UCLASS()
class TIMEATTACK_API ACheckpoint : public AActor {

    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ACheckpoint();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeAttack", Meta = (BlurprintProtected = "true"))
    int32 CheckpointNumber;

private:
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TimeAttack", Meta = (AllowPrivateAccess = "true"))
    USceneComponent* Root;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TimeAttack", Meta = (AllowPrivateAccess = "true"))
    UArrowComponent* Arrow;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TimeAttack", Meta = (AllowPrivateAccess = "true"))
    UBoxComponent* Trigger;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TimeAttack", Meta = (AllowPrivateAccess = "true"))
    UParticleSystemComponent* ParticleSystem;
};
