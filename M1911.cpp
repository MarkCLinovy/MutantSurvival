

#include "MutantSurvival.h"
#include "M1911.h"


AM1911::AM1911(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	WName = "M1911";
	FireRate = 650;
	clipSize = 5;
	bullets = clipSize;
	mag = 7;
	wDamage = 50;
	weaponRange = 5000;

	brapid = false;

	baseXSpread = 3;
	baseYSpread = 3;

	maxXSpread = 7;
	maxYSpread = 7;
}


