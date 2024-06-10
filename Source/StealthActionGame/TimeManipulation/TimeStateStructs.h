#pragma once

#include "CoreMinimal.h"
#include "TimeStateStructs.generated.h"

USTRUCT(BlueprintType)
struct STEALTHACTIONGAME_API FTimeState
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
	float RecordTime;
	
	virtual ~FTimeState() = default;
};

USTRUCT(BlueprintType)
struct STEALTHACTIONGAME_API FCharacterTimeState : public  FTimeState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector Location;
	UPROPERTY(EditAnywhere)
	FRotator Rotation;

	UPROPERTY(EditAnywhere)
	TMap<FName,FTransform> BonesTransforms; 
};