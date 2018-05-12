// Fill out your copyright notice in the Description page of Project Settings.

#include "Tracker.h"

// Sets default values
ATracker::ATracker()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATracker::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATracker::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
