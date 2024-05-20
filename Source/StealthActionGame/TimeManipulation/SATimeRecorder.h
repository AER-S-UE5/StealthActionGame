// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SATimeRecorder.generated.h"

USTRUCT(BlueprintType)
struct STEALTHACTIONGAME_API FTimeState
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
	float RecordTime;
	
	virtual ~FTimeState() = default;
	//bool operator==(const FTimeState&) const;
};

/**
 * 
 */

template <typename T= FTimeState>
class STEALTHACTIONGAME_API SATimeRecorder 
{

		
public:
	SATimeRecorder();
	virtual ~SATimeRecorder();

	virtual void RecordState();
	TArray<T> GetTimeStates();

protected:

	virtual void SyncProperties() =0;
	virtual void FillTimeState(T& TimeState) =0;
	
	float MaxRecordTime = 5.f;
	
	TArray<T> TimeStates;

	AGameStateBase* GameState;

	bool bIsRecording;

private:
	void RemoveUnwantedState();
};

template <typename T>
SATimeRecorder<T>::SATimeRecorder()
{
	bIsRecording = true;
	GameState = nullptr;
}


template <typename T>
SATimeRecorder<T>::~SATimeRecorder()
{
}

template <typename T>
void SATimeRecorder<T>::RecordState()
{
	T NewState ;
	FillTimeState(NewState);
	NewState.RecordTime = GameState->GetServerWorldTimeSeconds();
	TimeStates.Insert(NewState,0);
	RemoveUnwantedState();
}

template <typename T>
TArray<T> SATimeRecorder<T>::GetTimeStates()
{return TimeStates;}

template <typename T>
void SATimeRecorder<T>::RemoveUnwantedState()
{
	if(TimeStates.Num()<=0) return;
	T* LastState = &TimeStates[TimeStates.Num()-1];
	if(GameState->GetServerWorldTimeSeconds() -LastState->RecordTime >MaxRecordTime) TimeStates.Pop();
	LastState =nullptr;
}
