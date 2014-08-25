

#pragma once

#include "Weapon.h"
#include "Usable.h"
#include "GameFramework/Character.h"
#include "Hero.generated.h"

#define COLLISION_ITEM ECC_GameTraceChannel1

/**
 * 
 */
UCLASS()
class MUTANTSURVIVAL_API AHero : public ACharacter
{
	GENERATED_UCLASS_BODY()

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<UCameraComponent> FirstPersonCameraComponent;


public:
	float getHealth();

	UFUNCTION(reliable, server, WithValidation)
		void reloadWeapon();
protected:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Atttributes)
	bool bReloading;

	void OnClientFire();

	float reloadTime;

	void onFireClient();

	UFUNCTION(reliable, server, WithValidation)
	void serverFire();

	bool bCanFire;

	void reloadDone();

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void Tick(float DeltaSeconds) override; 

	virtual void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, class AActor* DamageCauser) override;
	
	TArray<AWeapon*> inventory;

	//handles moving forward/backward
	UFUNCTION()
		void MoveForward(float Val);
	//handles strafing
	UFUNCTION()
		void MoveRight(float Val);

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		TSubobjectPtr<USkeletalMeshComponent> FirstPersonMesh;

	//sets jump flag when key is pressed
	UFUNCTION()
		void OnStartJump();
	//clears jump flag when key is released
	UFUNCTION()
		void OnStopJump();

	UFUNCTION(reliable, server, WithValidation)
		void StopFire();

		void OnFire();

	UFUNCTION(reliable, server, WithValidation)
	void equipPrevWeapon();
	
	UFUNCTION(reliable, server, WithValidation)
	void equipNextWeapon();

	UFUNCTION(reliable, server, WithValidation)
		void OnUse();

	void equip(AWeapon* x);

	int32 currentWeaponIndex;

	virtual void PostInitializeComponents() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float pickUpRadius;

	IUsable * UseFocus;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LOL)
		TSubobjectPtr<USceneComponent> helper;

	FHitResult useHit;

public:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Atttributes)
		 AWeapon* currentWeapon;

	AWeapon* lastWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Atttributes)
		FVector GunOffset;
	
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Attributes)
		float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
		float maxHealth;






};
