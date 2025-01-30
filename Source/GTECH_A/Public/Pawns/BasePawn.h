#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

// GENERATED .H = DERNIER INCLUDE
#include "BasePawn.generated.h"

class AProjectile;
// FORWARD DECLARATION
class UBoxComponent;
class USoundCue;


UCLASS()
class GTECH_A_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void RotateTurret(FVector LookAtTarget);

	UPROPERTY(EditAnywhere, Category = "Canon properties");
	float InterpSpeed = 5.f;

	void Fire();
	

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Combat Properties")
	FVector ProjectileScale = FVector(5.f, 5.f, 5.f);

	UPROPERTY(EditAnywhere, Category = "Combat Properties")
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat Properties")
	USoundCue* FireSFX;

};
