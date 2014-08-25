

#pragma once

#include "Weapon.h"
#include "Hero.h"
#include "Particles/ParticleSystemComponent.h"

#include "Weapon_instant.generated.h"

/**
 * 
 */
UCLASS()
class AWeapon_instant : public AWeapon
{
	GENERATED_UCLASS_BODY()

	void fire(AActor *hero) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Atttributes)
		FName TrailTargetParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Atttributes)
	UParticleSystem* TrailFx;

	FVector CameraLoc;
	FRotator CameraRot;

	void execFireHelper();

	FHitResult useHit;

	AHero *hero;

	FVector MuzzleLocation;
	FRotator MuzzleRotation;

	FActorSpawnParameters SpawnParams;

	void simulateFire(FVector EndPoint) override;

	void execFire();

};
