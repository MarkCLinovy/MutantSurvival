

#pragma once

#include "Weapon.h"
#include "Weapon_projectile.generated.h"

/**
 * 
 */
UCLASS()
class AWeapon_projectile : public AWeapon
{
	GENERATED_UCLASS_BODY()
	void fire(AActor *hero) override;

	FVector CameraLoc;
	FRotator CameraRot;

	AActor *hero;

	FVector MuzzleLocation;
	FRotator MuzzleRotation;

	FActorSpawnParameters SpawnParams;

	void execFire();

};
