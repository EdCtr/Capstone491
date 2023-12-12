// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Containers/Map.h"
#include "InstructionsWidget.generated.h"

class UVerticalBox;
class AGame;
class UButton;
class UTextBlock;



USTRUCT(BlueprintType)
struct FQuestionStruct
{
	GENERATED_BODY()
public:
	FQuestionStruct(){}
	FQuestionStruct(FString Q, FString C1, FString C2, FString C3, FString C4, int32 CC)
	{
		Question = Q;
		Choice1 = C1;
		Choice2 = C2;
		Choice3 = C3;
		Choice4 = C4;
		CorrectChoice = CC;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Question;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Choice1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Choice2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Choice3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Choice4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CorrectChoice;
};


/**
 * 
 */
UCLASS()
class CAPSTONE491FINAL_API UInstructionsWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* TitleText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* InstructionsText;

	UPROPERTY(meta= (BindWidget))
	UTextBlock* QuestionText;

	UPROPERTY(meta=(BindWidget))
	UVerticalBox* ChoiceBox;

	UPROPERTY(meta = (BindWidget))
	UButton* ChoiceButton1;
	UPROPERTY(meta = (BindWidget))
	UButton* ChoiceButton2;
	UPROPERTY(meta = (BindWidget))
	UButton* ChoiceButton3;
	UPROPERTY(meta = (BindWidget))
	UButton* ChoiceButton4;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ChoiceText1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ChoiceText2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ChoiceText3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ChoiceText4;

	UPROPERTY(meta=(BindWidget))
	UButton* NextButton;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* ScoreText;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* ScoreText2;

	UPROPERTY()
	TMap<int32, FQuestionStruct> QuestionMap;

	void SetQuizVisibility(bool Visible);
	void SetIntroVisibility(bool Visible);
	void SetResultsVisibility(bool Visible);
	void SetInstructionVisibility(bool Visible);
	void SetInstructionText(FString Text);

	UFUNCTION()
	void ClickedNextButton();
	UFUNCTION()
	void ClickedStartButton();
	UFUNCTION()
	void ClickedChoiceButton1();
	UFUNCTION()
	void ClickedChoiceButton2();
	UFUNCTION()
	void ClickedChoiceButton3();
	UFUNCTION()
	void ClickedChoiceButton4();
	UFUNCTION()
	void PopulateTextMap();
	UFUNCTION()
	void SubmitAnswer(int32 Choice);

	void DisplayQuestion(int32 QuestionNum);
	void SetGameRef(AGame* Game);
	void QuizComplete(bool bQuizFirstAttempt);
	void QuizStart();
private:
	AGame* GameRef;
};
