// Fill out your copyright notice in the Description page of Project Settings.


#include "SACharacterTimeRecorder.h"

#include "StealthActionGame/SAGameMode.h"

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

void USACharacterTimeRecorder::StartRecorder()
{
	SATimeRecorder<FCharacterTimeState>::StartRecorder();
	
}

void USACharacterTimeRecorder::StopRecorder()
{
	SATimeRecorder<FCharacterTimeState>::StopRecorder();
	
}

// Called when the game starts
void USACharacterTimeRecorder::BeginPlay()
{
	Super::BeginPlay();
	Cast<ASAGameMode>(GetWorld()->GetAuthGameMode())->AddTimeRecorder(this);
	Mesh = GetOwner()->GetComponentByClass<USkeletalMeshComponent>();
	if(!ensureAlwaysMsgf(Mesh,TEXT("This Component Require a Skeletal Mesh Component"))) return;
	// ...
	SyncProperties();
	StartRecorder();
	
	
}


// Called every frame
void USACharacterTimeRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	RecordState();
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
	for (const auto BoneName : Mesh->GetAllSocketNames())
	{
		TimeState.BonesTransforms.Add(BoneName,Mesh->GetBoneTransform(BoneName,RTS_Component));
	}
}


