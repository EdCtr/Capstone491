// Fill out your copyright notice in the Description page of Project Settings.


#include "Scapel.h"
#include "Game.h"
#include "Kismet/GameplayStatics.h"
#include "CapstoneUtils.h"

void AScapel::BeginPlay()
{
	Super::BeginPlay();

	GameRef = Cast<AGame>(UGameplayStatics::GetActorOfClass(GetWorld(), AGame::StaticClass()));
	if(GameRef)
		CapstoneUtils::DebugMessage("Scapel: GameRef Found!", FColor::Green);
	else
		CapstoneUtils::DebugMessage("Scapel: GameRef Not Found!", FColor::Red);
}

void AScapel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AScapel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AScapel::UseTool()
{

}

void AScapel::OnGrabbed()
{
	Super::OnGrabbed();
	CapstoneUtils::DebugMessage("Scapel: Tool Grabbed", FColor::Green);

	if(bInitialGrab)
	{
		GameRef->SetSurgeryPhase(ESurgeryPhase::INCISION);
		GameRef->ExecuteGamePhase();
		bInitialGrab = false;
	}

}

void AScapel::OnReleased()
{
	Super::OnReleased();
	CapstoneUtils::DebugMessage("Scapel: Tool Released");

}
