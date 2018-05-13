/*
    Author: 刘臣轩
    Date: 2018.5.12
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor {

    GENERATED_BODY()

public:
    APickup();

    FORCEINLINE UStaticMeshComponent* GetMesh() const { return PickupMesh; }

    bool isActive();
    void setActive(bool NewPickupState);

    // Function to call when the pickup is collected
    UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
    void wasCollected();
    virtual void wasCollected_Implementation();

protected:
    // True when the pickup can be used, and false when pickup is deactivated
    bool activity;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
    UStaticMeshComponent* PickupMesh;
};
