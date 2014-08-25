

#pragma once

#include "SpawnSys.h"

#include "Survival.generated.h"

/**
 * 
 */
UCLASS()
class MUTANTSURVIVAL_API ASurvival : public AGameMode
{
	GENERATED_UCLASS_BODY()

	float spawnrate;

	int32 totalZombies;

	virtual void StartPlay() override;
	
	UPROPERTY(EditAnywhere, Category = Pawn)
		UClass* PawnClass;
	
	UFUNCTION(BlueprintCallable, Category = Attr)
	void decZombieCount();

	void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = attr)
	USpawnSys *GameSpawnSystem;

	void incrZombieCount();

	int32 getZombieCount();

	USpawnSys* getGameSpawnSystem();

	void setZombieCount(int32 value);

	UPROPERTY(EditAnywhere, Category = attr)
	int32 zombieCount;
};

