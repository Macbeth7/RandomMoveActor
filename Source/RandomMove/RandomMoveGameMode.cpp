// Copyright Epic Games, Inc. All Rights Reserved.

#include "RandomMoveGameMode.h"
#include "RandomMovePlayerController.h"
#include "RandomMoveCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARandomMoveGameMode::ARandomMoveGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARandomMovePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void ARandomMoveGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (ActorToSpawnClass)
	{
		FActorSpawnParameters SpawnParams;
		AMyActor* spawnActor = Cast<AMyActor>(GetWorld()->SpawnActor(ActorToSpawnClass, new FVector(0, 0, 0), new FRotator(0, 0, 0), SpawnParams));
		if (spawnActor)
		{
			spawnActor->StartAction();
		}
	}
}
