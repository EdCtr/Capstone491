// Fill out your copyright notice in the Description page of Project Settings.


#include "Game.h"
#include "CapstoneUtils.h"
#include "InstructionsWidget.h"
#include "Components/WidgetComponent.h"

// Sets default values
AGame::AGame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InstructionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InstructionWidget"));
	InstructionWidgetClass = CapstoneUtils::FindAsset<UUserWidget>(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/CapstoneContent/Blueprints/BPW_InstructionsWidgets.BPW_InstructionsWidgets_C'"));

	if (InstructionWidgetClass)
	{
		CapstoneUtils::DebugMessage(TEXT("Game: Instruction Widget Class found!"), FColor::Green);
		InstructionWidget->SetWidgetClass(InstructionWidgetClass);
		InstructionWidget->SetDrawSize(FVector2D(1920.0f, 1080.0f));


	}
	else
		CapstoneUtils::DebugMessage(TEXT("Game: Instruction Widget Class not found!"), FColor::Red);

}

// Called when the game starts or when spawned
void AGame::BeginPlay()
{
	Super::BeginPlay();

	InstructionWidgetRef = Cast<UInstructionsWidget>(InstructionWidget->GetWidget());
	if (InstructionWidgetRef)
	{
		CapstoneUtils::DebugMessage(TEXT("Game: Instruction Widget Ref Successfully Created!"), FColor::Green);
		InstructionWidgetRef->SetGameRef(this);
		InstructionWidgetRef->PopulateTextMap();
	}
	else
	{
		CapstoneUtils::DebugMessage(TEXT("Game: Instruction Widget Ref not found!"), FColor::Red);
	}

}

void AGame::SetGamePhase(EGamePhase Phase)
{
	CapstoneUtils::DebugMessage(FString::Printf(TEXT("Game: GamePhase Set - %s"), *CapstoneUtils::EnumToString(Phase)));
	GamePhase = Phase;
}

void AGame::SetSurgeryPhase(ESurgeryPhase Phase)
{
	CapstoneUtils::DebugMessage(FString::Printf(TEXT("Game: SurgeryPhase Set - %s"), *CapstoneUtils::EnumToString(Phase)));
	SurgeryPhase = Phase;
}

void AGame::ExecuteGamePhase()
{
	switch (GamePhase)
	{
	case EGamePhase::QUIZ:
		CapstoneUtils::DebugMessage(TEXT("Game: Quiz Phase Started"), FColor::Green);
		ResetAnsweredQuestions();
		InstructionWidgetRef->QuizStart();
		break;
	case EGamePhase::QUIZ_END:
		if(bQuizFirstAttempt)
		{
			CorrectAnswersFirstAttempt = CorrectAnswers;
			InstructionWidgetRef->QuizComplete(bQuizFirstAttempt);
			bQuizFirstAttempt = false;
		}
		else
		{
			CorrectAnswersSecondAttempt = CorrectAnswers;
			InstructionWidgetRef->QuizComplete(bQuizFirstAttempt);
		}
			

		break;
	case EGamePhase::SURGERY:
		ExecuteSurgeryPhase();
		break;
	case EGamePhase::END:
		break;
	}
}

// Called every frame
void AGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGame::SetTotalQuestions(int32 Total)
{
	CapstoneUtils::DebugMessage(TEXT("Game: Total Questions Set"), FColor::Green);
	TotalQuestions = Total;
}

void AGame::IncrementCorrectAnswers()
{
	CapstoneUtils::DebugMessage(TEXT("Game: Incremented Correct Answers"), FColor::Green);
	CorrectAnswers++;
}

void AGame::IncrementQuestionsAnswered()
{
	QuestionsAnswered++;
}

void AGame::ResetAnsweredQuestions()
{
	CorrectAnswers = 0;
	QuestionsAnswered = 0;
}

bool AGame::IsQuizComplete()
{
	if(QuestionsAnswered >=TotalQuestions)
		return true;
	else
		return false;
}

int32 AGame::GetAnsweredQuestions() const
{
	return QuestionsAnswered;
}

int32 AGame::GetCorrectAnswers() const
{
	return CorrectAnswers;
}

int32 AGame::GetTotalQuestions() const
{
	return TotalQuestions;
}

int32 AGame::GetCorrectAnswersFirstAttempt() const
{
	return CorrectAnswersFirstAttempt;
}

int32 AGame::GetCorrectAnswersSecondAttempt() const
{
	return CorrectAnswersSecondAttempt;
}


void AGame::ExecuteSurgeryPhase()
{
	switch (SurgeryPhase)
	{
	case ESurgeryPhase::START:
		InstructionWidgetRef->SetInstructionText("Step 1: Grab The Scalpel from the Rolling Table");
		break;
	case ESurgeryPhase::INCISION:
		InstructionWidgetRef->SetInstructionText("Step 2: Go up to Leg and Make an incision with the Scalpel at the proper region");
		break;
	case ESurgeryPhase::EXPOSURE:
		InstructionWidgetRef->SetInstructionText("Step 3: Grab the Electric Saw from The Rolling Table");
		break;
	case ESurgeryPhase::SAWING:
		InstructionWidgetRef->SetInstructionText("Step 4: Saw the Femoral Neck with the Electric Saw");
		break;
	case ESurgeryPhase::REMOVAL:
		InstructionWidgetRef->SetInstructionText("Step 5: Grab The Forceps from the table and pull out the fermoral head");
		break;
	case ESurgeryPhase::REAMING:
		InstructionWidgetRef->SetInstructionText("Step 6: Grab The Electric Screw Driver From the Table and ream hip acetabulum");
		break;
	case ESurgeryPhase::CUPPA:
		InstructionWidgetRef->SetInstructionText("Step 7: Grab The Cup and liner, then place it in the hip acetabulum");
		break;
	case ESurgeryPhase::BROACHING:
		InstructionWidgetRef->SetInstructionText("Step 8: Grab The Broach and Hammer from the table and Hammer it into the Femur Shaft. Then Grab the Ceramic Head and Place at the tip of the broach");
		break;
	case ESurgeryPhase::CONGRATS:
		InstructionWidgetRef->SetInstructionText("Congratulations you have successfully completed the surgery! You will now Retake the Quiz");

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
			{
				GamePhase = EGamePhase::QUIZ;
				ExecuteGamePhase();
			}, 5.0f, false);
		break;
	}
}
