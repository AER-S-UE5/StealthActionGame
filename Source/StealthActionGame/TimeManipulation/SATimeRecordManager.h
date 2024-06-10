// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SATimeRecorder.h"
#include "TimeStateStructs.h"

/**
 * 
 */
template<typename T=FTimeState>
class STEALTHACTIONGAME_API SATimeRecordManager
{
public:
	SATimeRecordManager();
	virtual ~SATimeRecordManager();

	void AddTimeRecorder(SATimeRecorder<T>* TimeRecorder);
	void StopRecording();

protected:
	TArray<SATimeRecorder<T>*> TimeRecorders;
};

template <typename T>
SATimeRecordManager<T>::SATimeRecordManager()
{
}

template <typename T>
SATimeRecordManager<T>::~SATimeRecordManager()
{
}

template <typename T>
void SATimeRecordManager<T>::AddTimeRecorder(SATimeRecorder<T>* TimeRecorder)
{
	TimeRecorders.Add(TimeRecorder);
}

template <typename T>
void SATimeRecordManager<T>::StopRecording()
{
	for (auto TimeRecorder : TimeRecorders)
	{
		TimeRecorder->StopRecorder();
	}
}
