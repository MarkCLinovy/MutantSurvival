

#include "MutantSurvival.h"
#include "Hero.h"
#include "SurvivalHud.h"


ASurvivalHud::ASurvivalHud(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/Textures/Hud/crosshair.crosshair'"));
	if (CrosshairTexObj.Object != NULL)
		CrosshairTex = CrosshairTexObj.Object;
}

void ASurvivalHud::DrawHUD()
{

	Super::DrawHUD();
	AHero *newOwner;
	newOwner = (AHero*)(GetOwningPawn());
	if (newOwner){

		GetOwningPlayerController()->GetViewportSize(sizeX, sizeY);

		DrawText(FString::SanitizeFloat(newOwner->getHealth()), FLinearColor::Black, 30, sizeY-50, NULL, 2, false);
		if (newOwner->currentWeapon){
			DrawText(FString::SanitizeFloat(newOwner->currentWeapon->getAmmo()), FLinearColor::Black, sizeX - 100, sizeY - 50, NULL, 2, false);
			DrawText(newOwner->currentWeapon->GetName(), FLinearColor::Black, sizeX - 500, sizeY - 50, NULL, 2, false);
		}
		// Draw very simple crosshair
		// find center of the Canvas
		const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
		// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
		const FVector2D CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)),
			(Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));
		// draw the crosshair
		FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
}
