// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricTool.h"
#include "CapstoneUtils.h"
// Sets default values

AElectricTool::AElectricTool()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ElectricToolMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ElectricToolMesh"));
	RootComponent = ElectricToolMesh;
	ElectricToolMesh->SetSimulatePhysics(true);
	ToolMesh->SetSimulatePhysics(false);
}

// Called when the game starts or when spawned
void AElectricTool::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AElectricTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AElectricTool::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AElectricTool::UseTool()
{

}


void AElectricTool::OnGrabbed()
{
	CapstoneUtils::DebugMessage("Electric Tool: Tool Grabbed", FColor::Green);

}

void AElectricTool::OnReleased()
{
	CapstoneUtils::DebugMessage("Electric Tool: Tool Released");
}
