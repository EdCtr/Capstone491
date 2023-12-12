// Fill out your copyright notice in the Description page of Project Settings.


#include "Tool.h"
#include "CapstoneUtils.h"
// Sets default values
ATool::ATool()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ToolMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ToolMesh"));
	RootComponent = ToolMesh;
	ToolMesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ATool::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATool::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATool::UseTool()
{
}

void ATool::OnGrabbed()
{
	CapstoneUtils::DebugMessage("Tool: Tool Grabbed", FColor::Green);
}

void ATool::OnReleased()
{
	CapstoneUtils::DebugMessage("Tool: Tool Released");
}

void ATool::ToolGrabbed(bool bisGrabbed)
{
	if(bisGrabbed)
	{
		OnGrabbed();
	}
	else
	{
		OnReleased();
	}
}

