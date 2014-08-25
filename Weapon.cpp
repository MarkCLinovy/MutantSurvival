

#include "MutantSurvival.h"
#include "Weapon.h"
#include "UnrealNetwork.h"

AWeapon::AWeapon(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}
FName AWeapon::getWName(){
	return WName;
}
void AWeapon::setFiring(bool fstate){
	firing = fstate;
}

bool AWeapon::getFiring(){
	return firing;
}
int32 AWeapon::getAmmo(){
	return bullets;
}

void AWeapon::reload(){
	bullets = clipSize;
	mag--;
}

void AWeapon::setSpreadPercentageNull(){
	spreadPercentage = 0;
}

void AWeapon::setSpreadPercentageOne(){
	spreadPercentage = 1;
}

float AWeapon::getSpreadPercentage(){
	return spreadPercentage;
}

void AWeapon::setSpreadPercentage(float x){
	spreadPercentage += x;
}

void AWeapon::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	DOREPLIFETIME(AWeapon, bullets);
	DOREPLIFETIME(AWeapon, firing);

}

bool AWeapon::isWeapon(){
	return true;
}
void AWeapon::fire(AActor *hero){
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString::FString("PARENT CLASS"));

}

void AWeapon::simulateFire(FVector EndPoint){

}