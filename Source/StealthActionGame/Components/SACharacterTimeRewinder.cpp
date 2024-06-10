// Fill out your copyright notice in the Description page of Project Settings.


#include "SACharacterTimeRewinder.h"

#include "Components/PoseableMeshComponent.h"
#include "StealthActionGame/SAGameMode.h"

// Sets default values for this component's properties
USACharacterTimeRewinder::USACharacterTimeRewinder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void USACharacterTimeRewinder::BeginPlay()
{
	Super::BeginPlay();
	SyncProperties();

	GameState = GetWorld()->GetGameState();
	Cast<ASAGameMode>(GetWorld()->GetAuthGameMode())->AddTimeRewinder(this);
	// ...
	Mesh =GetOwner()->GetComponentByClass<USkeletalMeshComponent>();
	ensureAlwaysMsgf(Mesh, TEXT("This component need A Skeletal Mesh Component"));
	PoseableMesh = GetOwner()->GetComponentByClass<UPoseableMeshComponent>();
	ensureAlwaysMsgf(PoseableMesh,TEXT("ThisComponent need a Poseable Mesh Component"));
}

void USACharacterTimeRewinder::SyncProperties()
{
	
}


// Called every frame
void USACharacterTimeRewinder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Rewind(DeltaTime);
	// ...
}

void USACharacterTimeRewinder::StartRewinder()
{
	SATimeRewinder<FCharacterTimeState>::StartRewinder();
	Mesh->SetHiddenInGame(true);
	Mesh->SetActive(false);
	PoseableMesh->SetHiddenInGame(false);
}

void USACharacterTimeRewinder::StopRewinder()
{
	SATimeRewinder<FCharacterTimeState>::StopRewinder();
	PoseableMesh->SetHiddenInGame(true);
	Mesh->SetHiddenInGame(false);
	Mesh->SetActive(true);
	
}

void USACharacterTimeRewinder::ExecuteRewindingTo(const FCharacterTimeState& TimeState)
{
	GetOwner()->SetActorLocation(TimeState.Location);
	GetOwner()->SetActorRotation(TimeState.Rotation);
	for (const auto& BoneTransformPair : TimeState.BonesTransforms)
	{
		PoseableMesh->SetBoneTransformByName(BoneTransformPair.Key,BoneTransformPair.Value,EBoneSpaces::ComponentSpace);
		
	}
}

void USACharacterTimeRewinder::Rewind(float DeltaSeconds)
{
	SATimeRewinder<FCharacterTimeState>::Rewind(DeltaSeconds);
}



