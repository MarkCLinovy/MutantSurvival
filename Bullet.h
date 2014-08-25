

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

/**
 * 
 */
UCLASS()
class MUTANTSURVIVAL_API ABullet : public AActor
{
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attr)
	float wDamage;

	UFUNCTION(WithValidation, Reliable, NetMulticast, Category = Network)
	void InitVelocity(FVector ShootDirection);
	
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	TSubobjectPtr<USphereComponent> CollisionComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	TSubobjectPtr<class UProjectileMovementComponent> MovementComp;


	/** inits velocity of the projectile in the shoot direction */

};
