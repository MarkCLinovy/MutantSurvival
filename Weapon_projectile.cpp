

#include "MutantSurvival.h"
#include "Weapon.h"
#include "Bullet.h"

#include "Weapon_projectile.h"


AWeapon_projectile::AWeapon_projectile(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}




void AWeapon_projectile::execFire(){
	//GetComponentByClass()
	if (bullets > 0){
		SpawnParams.Owner = this;
		SpawnParams.Instigator = hero->Instigator;

		hero->GetActorEyesViewPoint(CameraLoc, CameraRot);

		MuzzleLocation = CameraLoc + FTransform(CameraRot).TransformVector(MuzzleOffset);
		MuzzleRotation = CameraRot;

		GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString::FString("UWOT"));
		if (ProjectileClass != NULL){

			UWorld* const World = GetWorld();
			if (World)
			{

				// spawn the projectile at the muzzle
				MuzzleLocation.Z = MuzzleLocation.Z + 10;
				ABullet* const Projectile = World->SpawnActor<ABullet>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
				bullets--;
				if (Projectile)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString::FString("SPAWN SUCESSFUL"));
					// find launch direction
					FVector LaunchDir = MuzzleRotation.Vector();
					Projectile->InitVelocity(LaunchDir);
				}
			}


		}
		if (firing){
			GetWorldTimerManager().SetTimer(this, &AWeapon_projectile::execFire, 60 / FireRate, false);
		}
	}
	else{
		if (mag > 0){
			bullets = clipSize;
			mag--;
		}
	}
}
void AWeapon_projectile::fire(AActor *hero){


	this->hero = hero;
		execFire();


}