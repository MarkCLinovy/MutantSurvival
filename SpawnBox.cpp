

#include "MutantSurvival.h"
#include "SpawnBox.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnSystem.h"
#include "Hero.h"
#include "BasicAI.h"
#include "Survival.h"


ASpawnBox::ASpawnBox(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	if (Role = ROLE_Authority){
		collisionBox = PCIP.CreateDefaultSubobject<UBoxComponent>(this, "Collision Box");
		if (collisionBox){
			collisionBox->OnComponentBeginOverlap.AddDynamic(this, &ASpawnBox::OnBeginOverlap);
			collisionBox->OnComponentEndOverlap.AddDynamic(this, &ASpawnBox::OnEndOverlap);
			collisionBox->SetCollisionResponseToChannel(ECollisionChannel::COLLISION_ITEM, ECollisionResponse::ECR_Ignore);
			RootComponent = collisionBox;
		}
	}
}

void ASpawnBox::spawnAt(){

	FActorSpawnParameters SpawnParams;

	if (positions.Num() > 0){
		int32 r = FMath::RandRange(0, (positions.Num() - 1));
		spawnPos = positions[r];
	}

	if (spawnPos){
		ABasicAI* const Zombie = GetWorld()->SpawnActor<ABasicAI>(ZombieClass, spawnPos->GetActorLocation(), spawnPos->GetActorRotation(), SpawnParams);
		if(Zombie && Zombie->GetController() == nullptr)
			Zombie->SpawnDefaultController();
	}
	else{
		ABasicAI* const Zombie = GetWorld()->SpawnActor<ABasicAI>(ZombieClass, GetActorLocation(), GetActorRotation(), SpawnParams);
		if (Zombie && Zombie->GetController() == nullptr)
		Zombie->SpawnDefaultController();
	}

}

void ASpawnBox::OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (GetWorld())
		gameMode = UGameplayStatics::GetGameMode(GetWorld());
	if (Role == ROLE_Authority){
		if (OtherActor->IsA<AHero>())
		{
			herocount++;
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "IS A HERO");
			ASurvival* survivalMode = (ASurvival*)(gameMode);
			survivalMode->getGameSpawnSystem()->addToSpawns(this);
		}
	}
}

void ASpawnBox::OnEndOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GetWorld())
		gameMode = UGameplayStatics::GetGameMode(GetWorld());
	if (Role == ROLE_Authority){
		if (OtherActor->IsA<AHero>())
		{
			herocount--;
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "HERO LEFT");
			ASurvival* survivalMode = (ASurvival*)(gameMode);
		
			if (herocount<=0)
				survivalMode->getGameSpawnSystem()->removeFromSpawns(this);
		}
	}

}

