

#pragma once

#include "GameFramework/Actor.h"
#include "Usable.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS(abstract)
class AWeapon : public AActor, public IUsable
{
	GENERATED_UCLASS_BODY()

public:
	float getSpreadPercentage();

	void reload();

	UFUNCTION(BlueprintCallable, Category = Network)
	bool getFiring();

	void setSpreadPercentage(float x);

	void setSpreadPercentageNull();

	void setSpreadPercentageOne();

	virtual void simulateFire(FVector EndPoint);


protected:


	float spreadPercentage;

	float FireRate;

	UPROPERTY(EditAnywhere, Blueprintreadwrite, Category = Projectile)
	float wDamage;

	int32 clipSize;
	
	float weaponRange;


	bool brapid;

	float maxXSpread;

	float maxYSpread;

	float baseXSpread;
	
	float baseYSpread;

	FVector weaponMinSpread;

	FVector weaponMaxSpread;

	FVector weaponSpread;

	int32 mag;

public:
	virtual void fire(AActor *hero);
	
	UFUNCTION(BlueprintCallable, Category = Attr)
		FName getWName();

	UFUNCTION(BlueprintCallable, Category = Attr)
		int32 getAmmo();

	FName WName;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Attributes)
		int32 bullets;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Attributes)
	bool firing;

	bool isWeapon();

	void setFiring(bool fstate);

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABullet> ProjectileClass;

	/** Gun muzzle's offset from the camera location */
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;
};
