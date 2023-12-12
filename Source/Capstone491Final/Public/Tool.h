// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tool.generated.h"


UCLASS()
class CAPSTONE491FINAL_API ATool : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void UseTool() ;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tool")
	UStaticMeshComponent* ToolMesh;

	UFUNCTION(BlueprintCallable)
	void ToolGrabbed(bool bisGrabbed);

	virtual void OnGrabbed();
	virtual void OnReleased();

private:



};
