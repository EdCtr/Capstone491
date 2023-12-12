// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElectricTool.h"
#include "ElectricSaw.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE491FINAL_API AElectricSaw : public AElectricTool
{
	GENERATED_BODY()
public:
	AElectricSaw();
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

	bool bInitialGrab = true;
};
