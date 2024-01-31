// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;

	// 1.Calculate Center Point of canvas
	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f); 
	// 2.Calculate the position of the crosssair
	float CrosshairCenterWidth = (CrosshairTexture->GetSurfaceWidth() * 0.5f);
	float CrosshairCenterHeight = (CrosshairTexture->GetSurfaceHeight() * 0.5f);
	FVector2D CrossHairDrawPosition(Center.X - CrosshairCenterWidth, Center.Y - CrosshairCenterHeight);

	FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->GetResource(), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}
