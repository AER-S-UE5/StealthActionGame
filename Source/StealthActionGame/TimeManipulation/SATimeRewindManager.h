// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SATimeRewinder.h"
#include "TimeStateStructs.h"

/**
 * 
 */
template<typename  T = FTimeState>
class STEALTHACTIONGAME_API SATimeRewindManager
{
public:
	SATimeRewindManager();
	virtual ~SATimeRewindManager();

	void AddTimeRewinder(SATimeRewinder<T>* NewTimeRewinder);
	void Rewind();

protected:
	TArray<SATimeRewinder<T>*> TimeRewinders;
};

template <typename T>
SATimeRewindManager<T>::SATimeRewindManager()
{
}

template <typename T>
SATimeRewindManager<T>::~SATimeRewindManager()
{
}

template <typename T>
void SATimeRewindManager<T>::AddTimeRewinder(SATimeRewinder<T>* NewTimeRewinder)
{
	TimeRewinders.Add(NewTimeRewinder);
}

template <typename T>
void SATimeRewindManager<T>::Rewind()
{
	for (auto TimeRewinder : TimeRewinders)
	{
		TimeRewinder->StartRewinder();
	}
}
