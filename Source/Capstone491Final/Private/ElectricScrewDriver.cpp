// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricScrewDriver.h"

AElectricScrewDriver::AElectricScrewDriver()
{
		PrimaryActorTick.bCanEverTick = true;
}

void AElectricScrewDriver::BeginPlay()
{
		Super::BeginPlay();

}

void AElectricScrewDriver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElectricScrewDriver::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AElectricScrewDriver::OnGrabbed()
{
	Super::OnGrabbed();
	UseTool();
}

void AElectricScrewDriver::OnReleased()
{
		Super::OnReleased();
		StopUsingTool();
}
