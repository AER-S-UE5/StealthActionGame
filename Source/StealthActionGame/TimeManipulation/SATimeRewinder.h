// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SATimeRecorder.h"
#include "TimeStateStructs.h"
#include "Curves/CurveFloat.h"

class AGameStateBase;
/**
 * 
 */
template<typename T = FTimeState>
class STEALTHACTIONGAME_API SATimeRewinder
{
public:
	SATimeRewinder();
	virtual ~SATimeRewinder();

	void SetTimeRecorder(SATimeRecorder<T>* NewTimeRecorder);

	virtual void StartRewinder();
	virtual void StopRewinder();
	

protected:
	
	virtual void Rewind(float DeltaSeconds);

	bool bIsRewinding;

	SATimeRecorder<T>* TimeRecorder;

	TArray<T> TimeStates;

	virtual void ExecuteRewindingTo(const T& TimeState) = 0;
	virtual void SyncProperties() =0;

	FTimerHandle RewindingTimerHandle;

	float RewindingStartTime;

	UPROPERTY()
	AGameStateBase* GameState;

};

template <typename T>
SATimeRewinder<T>::SATimeRewinder(): bIsRewinding(false), TimeRecorder(nullptr)
{
	
}

template <typename T>
SATimeRewinder<T>::~SATimeRewinder()
{
}

template <typename T>
void SATimeRewinder<T>::SetTimeRecorder(SATimeRecorder<T>* NewTimeRecorder)
{
	TimeRecorder = NewTimeRecorder;
}

template <typename T>
void SATimeRewinder<T>::StartRewinder()
{
	bIsRewinding = true;
	RewindingStartTime = GameState->GetServerWorldTimeSeconds();
	ensureAlwaysMsgf(TimeRecorder,TEXT("This component require a Time Recorder Component..."));
	TimeStates = TimeRecorder->GetTimeStates();
	for (auto TimeState : TimeStates)
	{
		
	}
}

template <typename T>
void SATimeRewinder<T>::StopRewinder()
{
	bIsRewinding = false;
}

template <typename T>
void SATimeRewinder<T>::Rewind(float DeltaSeconds)
{
	if(!bIsRewinding) return;
	if(TimeStates.Num()<=0)
	{
		StopRewinder();
		return;
	}
	const T LastState = TimeStates.Pop();
	ExecuteRewindingTo(LastState);
	
}
