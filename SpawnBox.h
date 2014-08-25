

#pragma once

#include "Kismet/GameplayStatics.h"
#include "SpawnBox.generated.h"


#define COLLISION_ITEM ECC_GameTraceChannel1

/**
 * 
 */
UCLASS()
class MUTANTSURVIVAL_API ASpawnBox : public AActor
{
	GENERATED_UCLASS_BODY()

	TSubobjectPtr<UBoxComponent> collisionBox;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Atttributes)
	AActor* spawnPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Atttributes)
		TArray<AActor*> positions;

	UPROPERTY(EditDefaultsOnly, Category = Zombie)
		TSubclassOf<class ABasicAI> ZombieClass;

	AGameMode* gameMode;

	UFUNCTION()
	void OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnEndOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void spawnAt();

	int32 herocount;
};
