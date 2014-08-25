

#include "MutantSurvival.h"
#include "M16.h"


AM16::AM16(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	WName = "M16a4";
	FireRate = 550;
	clipSize = 30;
	bullets = clipSize;
	mag = 8;
	weaponRange = 5000;
	wDamage = 25;

	brapid = true;

	baseXSpread = 3;
	baseYSpread = 3;

	maxXSpread = 7;
	maxYSpread = 7;
}


