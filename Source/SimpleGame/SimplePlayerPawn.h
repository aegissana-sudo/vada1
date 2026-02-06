#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SimplePlayerPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SIMPLEGAME_API ASimplePlayerPawn : public APawn
{
    GENERATED_BODY()

public:
    ASimplePlayerPawn();

    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

    void AddScore(int32 Amount);

protected:
    virtual void BeginPlay() override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    UFUNCTION()
    void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* Camera;

    FVector CurrentVelocity;
    int32 Score;
};
