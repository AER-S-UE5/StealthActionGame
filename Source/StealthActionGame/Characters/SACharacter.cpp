// Fill out your copyright notice in the Description page of Project Settings.


#include "SACharacter.h"

#include "Components/CapsuleComponent.h"
#include "Components/PoseableMeshComponent.h"
#include "StealthActionGame/SAGameMode.h"
#include "StealthActionGame/Components/SACharacterTimeRecorder.h"
#include "StealthActionGame/Components/SACharacterTimeRewinder.h"

// Sets default values
ASACharacter::ASACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PoseableMesh = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("Poseable Mesh"));
	PoseableMesh->SetupAttachment(GetCapsuleComponent());

	TimeRecorder = CreateDefaultSubobject<USACharacterTimeRecorder>(TEXT("Time Recorder Component"));
	TimeRewinder = CreateDefaultSubobject<USACharacterTimeRewinder>(TEXT("Time Rewinder Component"));
	TimeRewinder->SetTimeRecorder(TimeRecorder);
}

// Called when the game starts or when spawned
void ASACharacter::BeginPlay()
{
	Super::BeginPlay();
	PoseableMesh->SetHiddenInGame(true);
	bIsRewinding = false;
	
}

void ASACharacter::RunRewindAbility()
{
	bIsRewinding= true;
	Cast<ASAGameMode>(GetWorld()->GetAuthGameMode())->RewindTime();
}

// Called every frame
void ASACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

