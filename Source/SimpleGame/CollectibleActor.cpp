#include "CollectibleActor.h"
#include "Components/StaticMeshComponent.h"

ACollectibleActor::ACollectibleActor()
{
    PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    Mesh->SetGenerateOverlapEvents(true);
    Mesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
}

void ACollectibleActor::BeginPlay()
{
    Super::BeginPlay();
}

void ACollectibleActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddActorLocalRotation(FRotator(0.0f, 90.0f * DeltaTime, 0.0f));
}
