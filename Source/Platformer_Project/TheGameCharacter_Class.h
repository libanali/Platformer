// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFrameWork/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "TheGameCharacter_Class.generated.h"

UCLASS()
class PLATFORMER_PROJECT_API ATheGameCharacter_Class : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATheGameCharacter_Class();


	FTimerHandle TimerForGame;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		USpringArmComponent* CameraBoom;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* Camera;


	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	


	void MoveRight(float Axis);
	void MoveForward(float Axis);


	void GameTimer();


	bool bDead;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Seconds;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Minutes;
};
