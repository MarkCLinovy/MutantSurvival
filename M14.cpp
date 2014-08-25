

#include "MutantSurvival.h"
#include "M14.h"


AM14::AM14(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	WName = "M14";
	FireRate = 625;
	clipSize = 20;
	bullets = clipSize;
	mag = 8;
	weaponRange = 5000;
	wDamage = 50;

	brapid = false;

	baseXSpread = 3;
	baseYSpread = 3;

	maxXSpread = 7;
	maxYSpread = 7;
}


