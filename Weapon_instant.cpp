

#include "MutantSurvival.h"
#include "Weapon.h"
#include "Weapon_instant.h"
#include "Bullet.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Hero.h"


AWeapon_instant::AWeapon_instant(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}



void AWeapon_instant::execFire()
{
	hero->GetActorEyesViewPoint(CameraLoc, CameraRot);
	
	
	//Basespread + (percantage of(maxSpread - baseSpread))

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::SanitizeFloat(spreadPercentage));

	weaponMaxSpread = FVector(0, ((float)FMath::RandRange(-maxXSpread, maxXSpread) / 100), ((float)FMath::RandRange(0, maxYSpread) / 100));
	weaponMinSpread = FVector(0, ((float)FMath::RandRange(-baseXSpread, baseXSpread) / 100), ((float)FMath::RandRange(0, baseYSpread) / 100));
	weaponSpread = weaponMinSpread + spreadPercentage * (weaponMaxSpread - weaponMinSpread);

	FVector EndTrace = CameraLoc + ((CameraRot.Vector()+weaponSpread) * weaponRange);
	
	const FName TraceTag("GetName");
	
	FCollisionQueryParams traceParams;

	//GetComponentByClass()
	if (bullets > 0){
		if (GetWorld()->LineTraceSingle(useHit, CameraLoc + (CameraRot.Vector() * 50), EndTrace, ECollisionChannel::ECC_Pawn, traceParams)){
			simulateFire(useHit.Location);
			if (Role == ROLE_Authority){
				UGameplayStatics::ApplyDamage(useHit.GetActor(), wDamage, hero->GetInstigatorController(), hero, UDamageType::StaticClass());
				bullets--;
			}
		}
		if (firing&&brapid){
			GetWorldTimerManager().SetTimer(this, &AWeapon_instant::execFireHelper, 60 / FireRate, false);
		}
	}
	else{
		if (mag > 0){
			hero->reloadWeapon();
		}
		else{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "No more mags");
		}
	}
}

void AWeapon_instant::simulateFire(FVector EndPoint){
	FVector pos;
	TArray<USceneComponent*> children;
	hero->FirstPersonCameraComponent->GetChildrenComponents(true, children);
	for (USceneComponent* a : children){
		if (a->GetName() == "FirstPersonMesh")
			pos = a->GetSocketLocation("MuzzleHelper");
	}

	if (TrailFx)
	{
		UParticleSystemComponent* TrailPSC = UGameplayStatics::SpawnEmitterAtLocation(this, TrailFx, pos);
		if (TrailPSC)
		{
			TrailPSC->SetVectorParameter(TrailTargetParam, EndPoint);
		}
	}
}
void AWeapon_instant::execFireHelper(){
	if (firing == true)
		execFire();
}

void AWeapon_instant::fire(AActor *hero){


	this->hero = (AHero*)hero;
	execFire();


}