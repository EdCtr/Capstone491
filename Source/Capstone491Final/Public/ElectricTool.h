// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tool.h"
#include "ElectricTool.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE491FINAL_API AElectricTool : public ATool
{
	GENERATED_BODY()

public:
	AElectricTool();
protected:
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void UseTool() override;
	virtual void OnGrabbed() override;
	virtual void OnReleased() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tool")
	USkeletalMeshComponent* ElectricToolMesh;
};

