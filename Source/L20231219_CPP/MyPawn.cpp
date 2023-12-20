// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"
#include "MyActorComponent.h"
#include "MyActor.h"

// 향상된 입력을 사용하기 위해서 추가
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left"));
	Left->SetupAttachment(Body);

	Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right"));
	Right->SetupAttachment(Body);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	RotateComponent = CreateDefaultSubobject<UMyActorComponent>(TEXT("RotateComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Script/Engine.StaticMesh'/Game/P38/Meshes/SM_P38_Body.SM_P38_Body'"));
	if (SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Propeller(TEXT("/Script/Engine.StaticMesh'/Game/P38/Meshes/SM_P38_Propeller.SM_P38_Propeller'"));
	if (SM_Body.Succeeded())
	{
		Left->SetStaticMesh(SM_Propeller.Object);
		Right->SetStaticMesh(SM_Propeller.Object);
	}

	Left->AddLocalOffset(FVector(37.0f, -21.0f, 1.0f));
	Right->AddLocalOffset(FVector(37.0f, 21.0f, 1.0f));

	Arrow->AddLocalOffset(FVector(100.0f, 0, 0));
	SpringArm->TargetArmLength = 150.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bEnableCameraRotationLag = true;

	Movement->MaxSpeed = 0.0f;
	Movement->Acceleration = 0.0f;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
	RotateComponent->Components.Add(Left);
	RotateComponent->Components.Add(Right);
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector());
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 특정 입력 액션들을 AMyPawn 클래스의 멤버 함수와 Bind(연결)해줍니다.
	// 이를 통해서 향상된 입력을 구현하며, 입력 액션이 발생시 필요한 함수가 호출됩니다.
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EIC && FireAction && PitchAndRollAction)
	{
		EIC->BindAction(FireAction, ETriggerEvent::Triggered, this, &AMyPawn::Fire);
		EIC->BindAction(PitchAndRollAction, ETriggerEvent::Triggered, this, &AMyPawn::PitchAndRoll);
	}
}


// Rocket 발사를 위한 함수입니다.
void AMyPawn::Fire(const FInputActionValue& Value)
{
	if (RoocketTemplate)
	{
		GetWorld()->SpawnActor<AActor>(RoocketTemplate, Arrow->GetComponentTransform());
	}
}

// 비행기 조작과 관련된 함수입니다.
void AMyPawn::PitchAndRoll(const FInputActionValue& Value)
{
	FVector2D RotationValue = Value.Get<FVector2D>();

	RotationValue = RotationValue* UGameplayStatics::GetWorldDeltaSeconds(GetWorld()) * 60.0f;

	AddActorLocalRotation(FRotator(RotationValue.Y,
		0,
		RotationValue.X
	));
}

