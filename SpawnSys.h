

#pragma once

#include "SpawnBox.h"

#include "Object.h"
#include "SpawnSys.generated.h"

/**
 * 
 */
UCLASS()
class MUTANTSURVIVAL_API USpawnSys : public UObject
{
	GENERATED_UCLASS_BODY()

	void spawn();
	
	TArray<ASpawnBox*> spawns;

	void addToSpawns(ASpawnBox *value);

	void removeFromSpawns(ASpawnBox *value);
};
