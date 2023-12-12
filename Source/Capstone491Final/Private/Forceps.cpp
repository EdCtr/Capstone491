// Fill out your copyright notice in the Description page of Project Settings.


#include "Forceps.h"

#include "CapstoneUtils.h"

// Called when the game starts or when spawned
void AForceps::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void  AForceps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void  AForceps::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void  AForceps::UseTool(){}
void  AForceps::OnGrabbed()
{
	Super::OnGrabbed();
	CapstoneUtils::DebugMessage("Forceps: Tool Grabbed", FColor::Green);
}
void  AForceps::OnReleased()
{
	Super::OnReleased();
	CapstoneUtils::DebugMessage("Forceps: Tool Released");
}