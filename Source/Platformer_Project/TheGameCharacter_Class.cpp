// Fill out your copyright notice in the Description page of Project Settings.


#include "TheGameCharacter_Class.h"
#include "Kismet/GameplayStatics.h"
#include "Finish_Flag.h"
#include "Engine.h"


// Sets default values
ATheGameCharacter_Class::ATheGameCharacter_Class()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);


	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 400.f;
	GetCharacterMovement()->AirControl = 0.1f;



	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 700.0f;
	CameraBoom->bUsePawnControlRotation = true;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;


	bDead = false;


}

// Called when the game starts or when spawned
void ATheGameCharacter_Class::BeginPlay()
{
	Super::BeginPlay();


	GetWorld()->GetTimerManager().SetTimer(TimerForGame, this, &ATheGameCharacter_Class::GameTimer, 1.0f, true, 3.1f);
	
}

// Called every frame
void ATheGameCharacter_Class::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ATheGameCharacter_Class::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);


	PlayerInputComponent->BindAxis("MoveRight", this, &ATheGameCharacter_Class::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &ATheGameCharacter_Class::MoveForward);

}



void ATheGameCharacter_Class::OnOverlapBegin(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor != nullptr)
	{

		AFinish_Flag* FinishFlag = Cast<AFinish_Flag>(OtherActor);



		if (FinishFlag)
		{

			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Orange, TEXT("Yeah"));

		}

	}

}

void ATheGameCharacter_Class::MoveRight(float Axis)
{

	if (!bDead)

	{

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);

	}


}

void ATheGameCharacter_Class::MoveForward(float Axis)
{

	if (!bDead)
	{

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);


	}

}

void ATheGameCharacter_Class::GameTimer()
{

	if (Seconds != 0)

	{
		Seconds -= 1;
	}

	else

	{
		if (Minutes == 0 && Seconds == 0)
		{

			bDead = true;


		}

		else

		{

			Minutes -= 1;

			Seconds = 59;
		}
	}


}

