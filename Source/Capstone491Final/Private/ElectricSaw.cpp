// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricSaw.h"
#include "CapstoneUtils.h"
#include "Game.h"
#include "Kismet/GameplayStatics.h"

AElectricSaw::AElectricSaw()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AElectricSaw::BeginPlay()
{
		Super::BeginPlay();
		

}

void AElectricSaw::Tick(float DeltaTime)
{
		Super::Tick(DeltaTime);

}

void AElectricSaw::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



void AElectricSaw::OnGrabbed()
{
	Super::OnGrabbed();
	CapstoneUtils::DebugMessage("Electric Tool: Tool Grabbed", FColor::Green);
	UseTool();
	if (bInitialGrab)
	{
		bInitialGrab = false;
		AGame* GameRef=Cast<AGame>(UGameplayStatics::GetActorOfClass(GetWorld(), AGame::StaticClass()));
		GameRef->SetSurgeryPhase(ESurgeryPhase::SAWING);
		GameRef->ExecuteGamePhase();
	}
}

void AElectricSaw::OnReleased()
{
	Super::OnReleased();
	CapstoneUtils::DebugMessage("Electric Tool: Tool Released");
	StopUsingTool();
}
