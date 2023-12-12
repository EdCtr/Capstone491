// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tool.h"
#include "Scapel.generated.h"

class AGame;
/**
 * 
 */
UCLASS()
class CAPSTONE491FINAL_API AScapel : public ATool
{
	GENERATED_BODY()
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void UseTool() override;

private:
	AGame* GameRef;
	virtual void OnGrabbed() override;
	virtual void OnReleased() override;

	bool bInitialGrab = true	;
};
