// Fill out your copyright notice in the Description page of Project Settings.


#include "SACharacterTimeRecorder.h"

/*bool FCharacterTimeState::operator==(const FCharacterTimeState& TimeState) const
{
	
	return FTimeState::operator==(TimeState);
}*/

// Sets default values for this component's properties
USACharacterTimeRecorder::USACharacterTimeRecorder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

TArray<FCharacterTimeState> USACharacterTimeRecorder::GetCharacterTimeStates()
{
	return GetTimeStates();
}


void USACharacterTimeRecorder::RecordState()
{
	SATimeRecorder::RecordState();
}

// Called when the game starts
void USACharacterTimeRecorder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	SyncProperties();
	
}


// Called every frame
void USACharacterTimeRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	RecordState();
	CharacterTimeStates = GetTimeStates();
}

void USACharacterTimeRecorder::SyncProperties()
{
	SATimeRecorder::MaxRecordTime = MaxRecordTime;
	GameState = GetWorld()->GetGameState();
}

void USACharacterTimeRecorder::FillTimeState(FCharacterTimeState& TimeState)
{
	TimeState.Location = GetOwner()->GetActorLocation();
	TimeState.Rotation = GetOwner()->GetActorRotation();
}


