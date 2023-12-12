// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElectricTool.h"
#include "ElectricScrewDriver.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE491FINAL_API AElectricScrewDriver : public AElectricTool
{
	GENERATED_BODY()
public:
	AElectricScrewDriver();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void UseTool() override;
	UFUNCTION(BlueprintImplementableEvent)
	void StopUsingTool();
	virtual void OnGrabbed() override;
	virtual void OnReleased() override;

};


