

#pragma once

#include "GameFramework/HUD.h"
#include "SurvivalHud.generated.h"

/**
 * 
 */
UCLASS()
class MUTANTSURVIVAL_API ASurvivalHud : public AHUD
{
	GENERATED_UCLASS_BODY()
	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
		UTexture2D* CrosshairTex;	// Set the crosshair texture

	int32 sizeX;
	int32 sizeY;

};
