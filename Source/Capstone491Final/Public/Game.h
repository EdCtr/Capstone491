// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game.generated.h"

class UInstructionsWidget;
class UWidgetComponent;

UENUM(BlueprintType)
enum class EGamePhase :uint8
{
	QUIZ,
	QUIZ_END,
	SURGERY,
	END,
};

UENUM(BlueprintType)
enum class ESurgeryPhase :uint8
{
	START,
	INCISION,
	EXPOSURE,
	SAWING,
	REMOVAL,
	REAMING,
	CUPPA,
	BROACHING,
	CONGRATS
};


UCLASS()
class CAPSTONE491FINAL_API AGame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGame();

	void ExecuteSurgeryPhase();
	UFUNCTION(BlueprintCallable)
	void SetSurgeryPhase(ESurgeryPhase Phase);
	void SetGamePhase(EGamePhase Phase);
	UFUNCTION(BlueprintCallable)
	void ExecuteGamePhase();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UWidgetComponent* InstructionWidget;

	void SetTotalQuestions(int32 Total);
	void IncrementCorrectAnswers();
	void IncrementQuestionsAnswered();
	void ResetAnsweredQuestions();
	bool IsQuizComplete();
	int32 GetAnsweredQuestions() const;
	int32 GetCorrectAnswers() const;
	int32 GetTotalQuestions() const;
	int32 GetCorrectAnswersFirstAttempt() const;
	int32 GetCorrectAnswersSecondAttempt() const;
	


	bool bIsSecondQuiz = false;
private:
		EGamePhase GamePhase;
		ESurgeryPhase SurgeryPhase = ESurgeryPhase::START;

		TSubclassOf<UUserWidget> InstructionWidgetClass;
		UInstructionsWidget* InstructionWidgetRef;

		int32 CorrectAnswers=0;
		int32 CorrectAnswersFirstAttempt=0;
		int32 CorrectAnswersSecondAttempt=0;
		int32 TotalQuestions=3;
		int32 QuestionsAnswered=0;

		bool bQuizFirstAttempt=true;
		
};
