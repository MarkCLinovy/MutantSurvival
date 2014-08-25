

#pragma once

#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "BasicAI.generated.h"
/**
 * 
 */
UCLASS()
class MUTANTSURVIVAL_API ABasicAI : public ACharacter
{
	GENERATED_UCLASS_BODY()
	
public:

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, Category = AttackMechanic)
		bool attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AttackMechanic)
	float attackRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AttackMechanic)
		float attackCD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = test)
		TSubclassOf<class ATriggerBox> newBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AttackMechanic)
		float attackRadius;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Attributes)
		float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
		float maxHealth;
private:
	float targetDelay;

	const float	MAX_TARGET_DELAY = 5;

	AActor *Player;

	int32 i = 0;

	void setAttack();

	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
		AActor *closestPlayer;

		void recalculateClosest();


};
