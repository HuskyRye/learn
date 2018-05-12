// Fill out your copyright notice in the Description page of Project Settings.

#include "Checkpoint.h"
#include "Engine/CollisionProfile.h"

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
    Trigger->SetHiddenInGame(false);
    Trigger->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
    Trigger->OnComponentBeginOverlap.AddDynamic(this, &ACheckpoint::onComponentBeginOverlap);

    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
}

void ACheckpoint::onComponentBeginOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}