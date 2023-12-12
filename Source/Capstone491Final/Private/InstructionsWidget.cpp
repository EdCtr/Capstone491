// Fill out your copyright notice in the Description page of Project Settings.

#include "InstructionsWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "CapstoneUtils.h"
#include "SlateBasics.h"
#include "Game.h"

void UInstructionsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind the OnClicked event to the OnClickButton function
	StartButton->OnClicked.AddDynamic(this, &UInstructionsWidget::ClickedStartButton);
	NextButton->OnClicked.AddDynamic(this, &UInstructionsWidget::ClickedNextButton);

	SetResultsVisibility(false);
	SetQuizVisibility(false);
	SetIntroVisibility(true);

	ChoiceButton1->OnClicked.AddDynamic(this, &UInstructionsWidget::ClickedChoiceButton1);
	ChoiceButton2->OnClicked.AddDynamic(this, &UInstructionsWidget::ClickedChoiceButton2);
	ChoiceButton3->OnClicked.AddDynamic(this, &UInstructionsWidget::ClickedChoiceButton3);
	ChoiceButton4->OnClicked.AddDynamic(this, &UInstructionsWidget::ClickedChoiceButton4);
}

void UInstructionsWidget::PopulateTextMap()
{
	CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Populating Text Map"), FColor::Green);

	FQuestionStruct Question1("Which surgical approach generally involves a smaller incision?", "Anterior Approach", "Posterior Approach", "Size of incision is the same for both", "Depends on the surgeon's preference", 1);
	FQuestionStruct Question2("What instrument is used for reshaping the acetabulum in hip replacement surgery?", "Scalpel", "Acetabular reamer", "Bone saw", "Chisel", 2);
	FQuestionStruct Question3(" How long does the Anterior Approach Total Hip Replacement surgery typically take?", "30 minutes to 1 hour", "1 to 2 hours", "3 to 4 hours", "5 to 6 hours", 2);
	FQuestionStruct Question4("After the Anterior Approach Total Hip Replacement, what activity should be avoided for several weeks?", "Walking", "Extreme hip flexion", "Arm movements", "Speaking loudly", 2);
	FQuestionStruct Question5("What is the main advantage of the Anterior Approach in Total Hip Replacement surgery?", "Shorter operation time", "Less muscle damage", "No need for anesthesia", "Immediate full weight-bearing", 2);

	QuestionMap.Add(0, Question1);
	QuestionMap.Add(1, Question2);
	QuestionMap.Add(2, Question3);
	QuestionMap.Add(3, Question4);
	QuestionMap.Add(4, Question5);

	if(GameRef)
		GameRef->SetTotalQuestions(QuestionMap.Num());
}

void UInstructionsWidget::DisplayQuestion(int32 QuestionNum)
{
	CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Displaying Question"), FColor::Green);

	FQuestionStruct QuestionStruct = QuestionMap[QuestionNum];

	QuestionText->SetText(FText::FromString(QuestionStruct.Question));
	ChoiceText1->SetText(FText::FromString(QuestionStruct.Choice1));
	ChoiceText2->SetText(FText::FromString(QuestionStruct.Choice2));
	ChoiceText3->SetText(FText::FromString(QuestionStruct.Choice3));
	ChoiceText4->SetText(FText::FromString(QuestionStruct.Choice4));
}


void UInstructionsWidget::SetQuizVisibility(bool Visible)
{
	if(Visible)
	{
		ChoiceBox->SetVisibility(ESlateVisibility::Visible);
		QuestionText->SetVisibility(ESlateVisibility::Visible);
		ChoiceButton1->SetVisibility(ESlateVisibility::Visible);
		ChoiceButton2->SetVisibility(ESlateVisibility::Visible);
		ChoiceButton3->SetVisibility(ESlateVisibility::Visible);
		ChoiceButton4->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		ChoiceBox->SetVisibility(ESlateVisibility::Collapsed);
		QuestionText->SetVisibility(ESlateVisibility::Collapsed);
		ChoiceButton1->SetVisibility(ESlateVisibility::Collapsed);
		ChoiceButton2->SetVisibility(ESlateVisibility::Collapsed);
		ChoiceButton3->SetVisibility(ESlateVisibility::Collapsed);
		ChoiceButton4->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInstructionsWidget::SetIntroVisibility(bool Visible)
{
	if (Visible)
	{
		TitleText->SetVisibility(ESlateVisibility::Visible);
		InstructionsText->SetVisibility(ESlateVisibility::Visible);
		StartButton->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		TitleText->SetVisibility(ESlateVisibility::Collapsed);
		InstructionsText->SetVisibility(ESlateVisibility::Collapsed);
		StartButton->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInstructionsWidget::SetResultsVisibility(bool Visible)
{
	if(Visible)
	{
		TitleText->SetVisibility(ESlateVisibility::Visible);
		InstructionsText->SetVisibility(ESlateVisibility::Visible);
		ScoreText->SetVisibility(ESlateVisibility::Visible);
		ScoreText2->SetVisibility(ESlateVisibility::Visible);
		NextButton->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		TitleText->SetVisibility(ESlateVisibility::Collapsed);
		InstructionsText->SetVisibility(ESlateVisibility::Collapsed);
		ScoreText->SetVisibility(ESlateVisibility::Collapsed);
		ScoreText2->SetVisibility(ESlateVisibility::Collapsed);
		NextButton->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInstructionsWidget::SetInstructionVisibility(bool Visible)
{
	if(Visible){
		InstructionsText->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		InstructionsText->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInstructionsWidget::SetInstructionText(FString Text)
{
	SetInstructionVisibility(true);
	FSlateFontInfo FontInfo = InstructionsText->GetFont();
	FontInfo.Size = 48;
	InstructionsText->SetFont(FontInfo);
	InstructionsText->SetText(FText::FromString(Text));
}

void UInstructionsWidget::ClickedNextButton()
{
	CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Clicked Next Button"), FColor::Green);

	SetResultsVisibility(false);
	if(GameRef->bIsSecondQuiz)
	{
		GameRef->SetGamePhase(EGamePhase::END);
		GameRef->ExecuteGamePhase();
	
	}
	else
	{
		GameRef->SetGamePhase(EGamePhase::SURGERY);
		GameRef->ExecuteGamePhase();
		GameRef->bIsSecondQuiz = true;
	}
}

void UInstructionsWidget::ClickedStartButton()
{
	CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Clicked Start Button"), FColor::Green);

	GameRef->SetGamePhase(EGamePhase::QUIZ);
	GameRef->ExecuteGamePhase();
}

void UInstructionsWidget::SetGameRef(AGame* Game)
{
	GameRef = Game;
	if(GameRef)
		CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: GameRef Set"), FColor::Green);
	else
		CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: GameRef not set"), FColor::Red);
}

void UInstructionsWidget::QuizComplete(bool bQuizFirstAttempt)
{
		SetQuizVisibility(false);
		SetResultsVisibility(true);

		TitleText->SetText(FText::FromString("Quiz Complete!"));
		if(bQuizFirstAttempt)
			SetInstructionText("Here are your results");
		else
			SetInstructionText("Here are your results from the second attempt");

		ScoreText->SetText(FText::FromString("First Attempt: "+FString::FromInt(GameRef->GetCorrectAnswersFirstAttempt()) + "/" + FString::FromInt(GameRef->GetTotalQuestions())));
		if (bQuizFirstAttempt)
			ScoreText2->SetText(FText::FromString(TEXT("Second Attempt: ?/?")));
		else
			ScoreText2->SetText(FText::FromString(TEXT("Second Attempt: " + FString::FromInt(GameRef->GetCorrectAnswersSecondAttempt()) + "/" + FString::FromInt(GameRef->GetTotalQuestions()))));
		

}

void UInstructionsWidget::ClickedChoiceButton1(){
	SubmitAnswer(1);
}


void UInstructionsWidget::ClickedChoiceButton2()
{
	SubmitAnswer(2);
}

void UInstructionsWidget::ClickedChoiceButton3()
{
	SubmitAnswer(3);
}

void UInstructionsWidget::ClickedChoiceButton4()
{
	SubmitAnswer(4);
}

void UInstructionsWidget::SubmitAnswer(int32 Choice)
{
	CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Submitted Answer"), FColor::Green);
	if (QuestionMap[GameRef->GetAnsweredQuestions()].CorrectChoice == Choice)
	{
		GameRef->IncrementCorrectAnswers();
		CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Correct Answer"), FColor::Green);
	}
	else
	{
		CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Incorrect Answer"));
	}
	GameRef->IncrementQuestionsAnswered();

	if (GameRef->IsQuizComplete())
	{
		CapstoneUtils::DebugMessage(TEXT("InstructionsWidget: Quiz Complete"), FColor::Green);
		GameRef->SetGamePhase(EGamePhase::QUIZ_END);
		GameRef->ExecuteGamePhase();
	}
	else
	{
		DisplayQuestion(GameRef->GetAnsweredQuestions());
	}

}

void UInstructionsWidget::QuizStart()
{
	SetIntroVisibility(false);
	SetQuizVisibility(true);

	GameRef->ResetAnsweredQuestions();
	DisplayQuestion(GameRef->GetAnsweredQuestions());
}
