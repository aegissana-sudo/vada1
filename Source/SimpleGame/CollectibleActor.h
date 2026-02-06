#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleActor.generated.h"

UCLASS()
class SIMPLEGAME_API ACollectibleActor : public AActor
{
    GENERATED_BODY()

public:
    ACollectibleActor();

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;
};
