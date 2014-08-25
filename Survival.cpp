

#include "MutantSurvival.h"
#include "Survival.h"
#include "Hero.h"
#include "SurvivalHud.h"
#include "SpawnSys.h"

ASurvival::ASurvival(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	HUDClass = ASurvivalHud::StaticClass();
	spawnrate = 0;
	DefaultPawnClass = AHero::StaticClass();

}

void ASurvival::StartPlay(){
	if(Role == ROLE_Authority){
	Super::StartPlay();
	GameSpawnSystem = NewObject<USpawnSys>(this, USpawnSys::StaticClass());

	zombieCount = 0;

	if (zombieCount == 0){
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, "Zombies are all dead, gj");
	}
	}
}

void ASurvival::Tick(float DeltaSeconds){
	if (Role == ROLE_Authority){
		if (spawnrate > 0){
			spawnrate -= DeltaSeconds;
		}
		else if (totalZombies <= 50){
			GameSpawnSystem->spawn();
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, "SPAWNING");

			incrZombieCount();
			spawnrate = 3;
		}
	}
}
USpawnSys* ASurvival::getGameSpawnSystem(){
	return GameSpawnSystem;
}

void ASurvival::decZombieCount(){
	zombieCount--;
}

void ASurvival::incrZombieCount(){
	zombieCount++;
	totalZombies++;
}

int32 ASurvival::getZombieCount(){
	return zombieCount;
}

void ASurvival::setZombieCount(int32 value){
	zombieCount = value;
}