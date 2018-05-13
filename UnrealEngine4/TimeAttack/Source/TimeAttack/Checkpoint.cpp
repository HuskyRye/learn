// Fill out your copyright notice in the Description page of Project Settings.

#include "Checkpoint.h"

#include "Engine/CollisionProfile.h"
#include "TimeAttackPawn.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

    Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
    Arrow->SetupAttachment(Root);

    Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
    Trigger->SetupAttachment(Root);
    Trigger->SetRelativeScale3D(FVector(1.0, 6.5, 6.5));
    Trigger->SetVisibility(true);
    Trigger->bGenerateOverlapEvents = false;
    Trigger->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
    Trigger->OnComponentEndOverlap.AddDynamic(this, &ACheckpoint::onComponentEndOverlap);

    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
}

void ACheckpoint::onComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    ATimeAttackPawn* TimeAttackPawn = Cast<ATimeAttackPawn>(OtherActor);
    if (TimeAttackPawn && FVector::DotProduct(Arrow->GetComponentRotation().Vector(), TimeAttackPawn->GetVelocity()) > 0) {
        checkpointCleared(checkpointNumber);
        Trigger->SetHiddenInGame(true);
        ParticleSystem->SetHiddenInGame(true);
        Trigger->bGenerateOverlapEvents = false;
    }
}

void ACheckpoint::checkpointCleared(int32 NextCheckpoint)
{
}