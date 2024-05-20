// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StealthActionGame/TimeManipulation/SATimeRecorder.h"
#include "SACharacterTimeRecorder.generated.h"

USTRUCT(BlueprintType)
struct STEALTHACTIONGAME_API FCharacterTimeState : public  FTimeState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector Location;
	UPROPERTY(EditAnywhere)
	FRotator Rotation;
	
	//virtual bool operator==(const FCharacterTimeState&) const;
	
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEALTHACTIONGAME_API USACharacterTimeRecorder : public UActorComponent, public SATimeRecorder<FCharacterTimeState>
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USACharacterTimeRecorder();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FCharacterTimeState> GetCharacterTimeStates();


	virtual void RecordState() override;

protected:
	
	UPROPERTY(EditDefaultsOnly,Category="Settings")
	float MaxRecordTime = 5.f;

	UPROPERTY(EditAnywhere,Category="TimeStateRecording", meta=(AllowPrivateAccess = "true"))
	TArray<FCharacterTimeState> CharacterTimeStates;
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void SyncProperties() override;
	virtual void FillTimeState(FCharacterTimeState& TimeState) override;
};
