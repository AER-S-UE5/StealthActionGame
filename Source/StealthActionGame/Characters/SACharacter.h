// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SACharacter.generated.h"

class UPoseableMeshComponent;
class USACharacterTimeRewinder;
class USACharacterTimeRecorder;

UCLASS()
class STEALTHACTIONGAME_API ASACharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASACharacter();

	UPROPERTY(BlueprintReadOnly)
	bool bIsRewinding;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UPoseableMeshComponent* PoseableMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USACharacterTimeRecorder> TimeRecorder;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USACharacterTimeRewinder> TimeRewinder;

	UFUNCTION(BlueprintCallable)
	void RunRewindAbility();
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
