// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StealthActionGame/TimeManipulation/SATimeRecordManager.h"
#include "SACharacterTimeRecordManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEALTHACTIONGAME_API USACharacterTimeRecordManager : public UActorComponent, public SATimeRecordManager<FCharacterTimeState>
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USACharacterTimeRecordManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
