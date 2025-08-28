// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyActor::StartAction()
{
	FVector beforeActorLoation;
	FVector ActorLoation;

	this->SetActorLocation(FVector(0, 0, 0));//Start 0, 0, 0
	double total_moving_distance = 0;
	int radom_event_active_count = 0;
	UE_LOG(LogTemp, Error, TEXT("Move Start!"));
	for (size_t i = 0; i < 10; i++)
	{
		beforeActorLoation = this->GetActorLocation();
		Move();
		ActorLoation = this->GetActorLocation();
		
		if (RandomEvent())radom_event_active_count++;

		UE_LOG(LogTemp, Warning, TEXT("Step %i Move Distance : %f"), i + 1, distance(beforeActorLoation, ActorLoation));
		total_moving_distance += distance(beforeActorLoation, ActorLoation);
	}
	UE_LOG(LogTemp, Error, TEXT("Move End!"));
	UE_LOG(LogTemp, Warning, TEXT("Tototal Moving Distance : %f"), total_moving_distance);
	UE_LOG(LogTemp, Warning, TEXT("Radom Event Active Count : %d"), radom_event_active_count);
}

void AMyActor::Move()
{
	FVector RandomOffset = this->GetActorLocation();

	RandomOffset.X += step();
	RandomOffset.Y += step();

	UE_LOG(LogTemp, Warning, TEXT("X : %f, Y : %f"), RandomOffset.X, RandomOffset.Y);
	this->SetActorLocation(RandomOffset);
}

double AMyActor::distance(FVector& v1, FVector& v2)
{
	double v1x = v1.X;
	double v1y = v1.Y;
	double v2x = v2.X;
	double v2y = v2.Y;

	return sqrt(pow(v1x - v2x, 2) + pow(v1y - v2y, 2));;
}

bool AMyActor::RandomEvent()
{
	//int probability = FMath::RandRange(1, 100);
	if (step() > 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("▶▶▶▶▶ RandomEvent ◀◀◀◀◀")));
		return true;
	}
	return false;
}

int AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

