

#include "MutantSurvival.h"
#include "Usable.h"

//////////////////////////////////////////////////////////////////////////
// ToStringInterface

UUsable::UUsable(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{

}

//This is required for compiling,  and its the base version, you can put something here and it will be the default behaviour
void IUsable::OnUsed(AController * user)
{

}

void IUsable::DisplayPrompt(UCanvas * Canvas, AController * user)
{
}