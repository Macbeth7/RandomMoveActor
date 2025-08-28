// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyActor.h"
#include "RandomMoveGameMode.generated.h"

UCLASS(minimalapi)
class ARandomMoveGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARandomMoveGameMode();

	UPROPERTY(EditDefaultsOnly, Category = "Spawn Settings")
	TSubclassOf<AMyActor> ActorToSpawnClass; // TSubclassOf는 에디터에서 클래스 타입을 지정할 수 있게 해줍니다.

	virtual void BeginPlay() override;
};



