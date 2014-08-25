

#include "MutantSurvival.h"
#include "BasicAI.h"
#include "UnrealNetwork.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Kismet/GameplayStatics.h"

ABasicAI::ABasicAI(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}


void ABasicAI::BeginPlay(){
	if (Role == ROLE_Authority){
		Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		closestPlayer = Player;
		attackRate = 50;
		attackCD = 0;
		attackRadius = 130;
		targetDelay = 0;
	}
}

void ABasicAI::Tick(float DeltaSeconds){
	if (Role == ROLE_Authority){
		//Recalculate the closest target every targetDelay seconds
			if (targetDelay >= 0){				
				targetDelay -= DeltaSeconds;
			}else {
				recalculateClosest();
			}

			//attack every attackCD seconds if target in Range
			if (attackCD >= 0){
				attackCD -= DeltaSeconds;
			}
			else{
					if (GetDistanceTo(closestPlayer) <= attackRadius && attackCD <= 0){
						Controller->StopMovement();
						attack = true;
						UGameplayStatics::ApplyDamage(closestPlayer, 5, Controller, this, UDamageType::StaticClass());
						GetWorldTimerManager().SetTimer(this, &ABasicAI::setAttack, 1, false);
						attackCD = 60/attackRate;
						
					}
			}
			if (GetVelocity().IsZero() && attack==false){
				recalculateClosest();
			}
	}
}

void ABasicAI::setAttack(){
	attack = false;
}

void ABasicAI::recalculateClosest(){
	Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	do{
		if (GetDistanceTo(Player) < GetDistanceTo(closestPlayer)){
			closestPlayer = Player;
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT("CLOSER"));
		}
		Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), i);
		i++;
	} while (Player);
	targetDelay = MAX_TARGET_DELAY;
	UNavigationSystem::SimpleMoveToActor(Controller, closestPlayer);
	i = 0;
}

void ABasicAI::PostInitializeComponents(){
	Super::PostInitializeComponents();
	if (Role == ROLE_Authority){
		health = maxHealth;
		
	}
}

void ABasicAI::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABasicAI, health);
	DOREPLIFETIME(ABasicAI, attack);

}

