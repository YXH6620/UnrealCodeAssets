// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BlasterHUD.generated.h"
USTRUCT(BlueprintType)
struct FHUDPackage
{
	GENERATED_BODY()
public:
	//...
	FLinearColor CrosshairsColor; // ×¼ÐÇÑÕÉ«
};

UCLASS()
class BLASTER_API ABlasterHUD : public AHUD
{
	GENERATED_BODY()

public:

	void DrawCrosshair(UTexture2D* Texture, FVector2D ViewportCenter, FVector2D Spread, FLinearColor CrosshairColor);
};