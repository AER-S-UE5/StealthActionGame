// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimeManipulation/SATimeRewinder.h"
#include "SAGameMode.generated.h"

class USACharacterTimeRecordManager;
class USACharacterTimeRewindManager;
/**
 * 
 */
UCLASS()
class STEALTHACTIONGAME_API ASAGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASAGameMode();
	void AddTimeRewinder(SATimeRewinder<FCharacterTimeState>* NewTimeRewinder);
	void AddTimeRecorder(SATimeRecorder<FCharacterTimeState>* NewTimeRecorder);
	void RewindTime();
	
protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USACharacterTimeRewindManager> CharacterTimeRewindManager;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USACharacterTimeRecordManager> CharacterTimeRecordManager;
	
};
