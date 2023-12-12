// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CAPSTONE491FINAL_API CapstoneUtils
{
public:
	CapstoneUtils();
	~CapstoneUtils();


	template<typename AssetType>
	static TSubclassOf<AssetType> FindAsset(const TCHAR* AssetPath)
	{
		ConstructorHelpers::FClassFinder<AssetType> AssetClassFinder(AssetPath);

		if (AssetClassFinder.Succeeded())
		{
			return AssetClassFinder.Class;
		}

		return nullptr;
	}

	template<typename TEnum>
	static FString EnumToString(TEnum EnumValue)
	{
		const UEnum* EnumPtr = StaticEnum<TEnum>();
		if (!EnumPtr) return FString("Invalid");

		return EnumPtr->GetNameByValue(static_cast<int64>(EnumValue)).ToString();
	}

	static void DebugMessage(const FString& Message)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, Message);
	}

	static void DebugMessage(const FString& Message, int32 Key)
	{
		DebugMessage(Message, Key, 15.0f, FColor::Red);
	}

	static void DebugMessage(const FString& Message, FColor DisplayColor)
	{
		DebugMessage(Message, -1, 15.0f, DisplayColor);

	}
	static void DebugMessage(const FString& Message, int32 Key, float TimeToDisplay)
	{
		DebugMessage(Message, Key, TimeToDisplay, FColor::Red);

	}
	static void DebugMessage(const FString& Message, float TimeToDisplay, FColor DisplayColor)
	{
		DebugMessage(Message, -1, TimeToDisplay, DisplayColor);

	}
	static void DebugMessage(const FString& Message, int32 Key, float TimeToDisplay, FColor DisplayColor)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, TimeToDisplay, DisplayColor, Message);
		}
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
	}

};
