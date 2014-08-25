

#include "MutantSurvival.h"
#include "Bullet.h"
#include "Weapon.h"


ABullet::ABullet(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	AWeapon *origin = (AWeapon*)(GetOwner());
	CollisionComp = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->AlwaysLoadOnClient = true;
	CollisionComp->AlwaysLoadOnServer = true;
	CollisionComp->bTraceComplexOnMove = true;
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);

	RootComponent = CollisionComp;
	MovementComp = PCIP.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	MovementComp->UpdatedComponent = CollisionComp;
	MovementComp->InitialSpeed = 2000.0f;
	MovementComp->MaxSpeed = 2000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->ProjectileGravityScale = 0.f;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	bReplicateInstigator = true;
	bReplicateMovement = false;
}

bool ABullet::InitVelocity_Validate(FVector ShootDirection)
{
	return true;
}


void ABullet::InitVelocity_Implementation(FVector ShootDirection)
{
	if (MovementComp)
	{
		// set the projectile's velocity to the desired direction
		MovementComp->Velocity = ShootDirection * MovementComp->InitialSpeed;
	}
}

