// Fill out your copyright notice in the Description page of Project Settings.


#include "Finish_Flag.h"

// Sets default values
AFinish_Flag::AFinish_Flag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFinish_Flag::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinish_Flag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

