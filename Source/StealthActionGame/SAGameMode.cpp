// Fill out your copyright notice in the Description page of Project Settings.


#include "SAGameMode.h"

#include "Components/SACharacterTimeRecordManager.h"
#include "Components/SACharacterTimeRewindManager.h"

ASAGameMode::ASAGameMode()
{
	CharacterTimeRewindManager = CreateDefaultSubobject<USACharacterTimeRewindManager>(TEXT("Character Time Rewind Manager"));
	CharacterTimeRecordManager = CreateDefaultSubobject<USACharacterTimeRecordManager>(TEXT("Character time Record Manager"));
}

void ASAGameMode::AddTimeRewinder(SATimeRewinder<FCharacterTimeState>* NewTimeRewinder)
{
	CharacterTimeRewindManager->AddTimeRewinder(NewTimeRewinder);
}

void ASAGameMode::AddTimeRecorder(SATimeRecorder<FCharacterTimeState>* NewTimeRecorder)
{
	CharacterTimeRecordManager->AddTimeRecorder(NewTimeRecorder);
}

void ASAGameMode::RewindTime()
{
	CharacterTimeRecordManager->StopRecording();
	CharacterTimeRewindManager->Rewind();
}
