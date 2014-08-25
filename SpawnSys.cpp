

#include "MutantSurvival.h"
#include "SpawnSys.h"


USpawnSys::USpawnSys(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void USpawnSys::spawn(){
	if (spawns.Num() > 0){
		const int32 RandomIndex = FMath::RandRange(0, spawns.Num() - 1);
		spawns[RandomIndex]->spawnAt();
	}
}
void USpawnSys::addToSpawns(ASpawnBox *value){
	if (this)
	spawns.Add(value);
}

void USpawnSys::removeFromSpawns(ASpawnBox *value){
	spawns.Remove(value);
}
