// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimeStateStructs.h"
#include "GameFramework/GameStateBase.h"

template <typename T= FTimeState>
class STEALTHACTIONGAME_API SATimeRecorder 
{

		
public:
	SATimeRecorder();
	virtual ~SATimeRecorder();

	virtual void RecordState();

	virtual void StartRecorder();
	virtual void StopRecorder();
	TArray<T> GetTimeStates();

protected:

	virtual void SyncProperties() =0;
	virtual void FillTimeState(T& TimeState) =0;
	
	float MaxRecordTime = 5.f;
	
	TArray<T> TimeStates;

	UPROPERTY()
	AGameStateBase* GameState;

	bool bIsRecording;

	FTimerHandle RecordingTimerHandle;

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
	TimeStates.Add(NewState);
	RemoveUnwantedState();
}

template <typename T>
void SATimeRecorder<T>::StartRecorder()
{
	bIsRecording = true;
}

template <typename T>
void SATimeRecorder<T>::StopRecorder()
{
	bIsRecording = false;
}

template <typename T>
TArray<T> SATimeRecorder<T>::GetTimeStates()
{return TimeStates;}

template <typename T>
void SATimeRecorder<T>::RemoveUnwantedState()
{
	if(TimeStates.Num()<=0) return;
	const auto LastState = TimeStates[0];
	if(GameState->GetServerWorldTimeSeconds() -LastState.RecordTime >MaxRecordTime) TimeStates.RemoveAt(0);
}
