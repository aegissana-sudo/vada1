#include "SimplePlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "CollectibleActor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"

ASimplePlayerPawn::ASimplePlayerPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    Mesh->SetGenerateOverlapEvents(true);
    Mesh->SetCollisionProfileName(TEXT("Pawn"));

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bEnableCameraLag = true;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    AutoPossessPlayer = EAutoReceiveInput::Player0;
    Score = 0;
}

void ASimplePlayerPawn::BeginPlay()
{
    Super::BeginPlay();

    Mesh->OnComponentBeginOverlap.AddDynamic(this, &ASimplePlayerPawn::HandleOverlap);
}

void ASimplePlayerPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!CurrentVelocity.IsNearlyZero())
    {
        const FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime * 600.0f);
        SetActorLocation(NewLocation);
    }
}

void ASimplePlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    PlayerInputComponent->BindAxis("MoveForward", this, &ASimplePlayerPawn::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASimplePlayerPawn::MoveRight);
}

void ASimplePlayerPawn::MoveForward(float Value)
{
    CurrentVelocity.X = Value;
}

void ASimplePlayerPawn::MoveRight(float Value)
{
    CurrentVelocity.Y = Value;
}

void ASimplePlayerPawn::AddScore(int32 Amount)
{
    Score += Amount;
    UE_LOG(LogTemp, Log, TEXT("Score: %d"), Score);
}

void ASimplePlayerPawn::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (ACollectibleActor* Collectible = Cast<ACollectibleActor>(OtherActor))
    {
        Collectible->Destroy();
        AddScore(1);
    }
}
