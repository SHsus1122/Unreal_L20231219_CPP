// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 최적화를 위해서 해당 액터에 대해서 Tick 프레임을 켜고 끌 수 있습니다.
	PrimaryActorTick.bCanEverTick = false;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Script/Engine.StaticMesh'/Game/Rocket/Meshes/SM_Rocket.SM_Rocket'"));
	if (SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}
	
	// Rocket 중력 비활성화, 최고속도 조절, 시작속도 조절
	Movement->ProjectileGravityScale = 0.0f;
	Movement->MaxSpeed = 500.0f;
	Movement->InitialSpeed = 500.0f;

	// Rocket 방향을 정면을 향해 날아가게 해주기 위해서 회전 적용
	Body->AddLocalRotation(FRotator(-90.0f, 0, 0));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 3초후에 자동 소멸
	SetLifeSpan(3.0f);

	// 오버랩 이벤트 발생시 해당 액터(this)즉, MyActor 에 해당합니다.
	// 그리고 AddDynamic 함수는 함수 포인터를 인자로 받아서 해당 함수를 델리게이트에 추가합니다.
	// 따라서 &AMyActor::ProcessActorBeginOverlap를 사용하여 AMyActor 클래스의 
	// ProcessActorBeginOverlap 함수의 주소를 얻어 해당 함수를 델리게이트에 추가하고 있습니다.
	// 
	// 즉, AMyActor 에 오버랩 이벤트 발생시 ProcessActorBeginOverlap 함수를 호출한다는 의미입니다.
	OnActorBeginOverlap.AddDynamic(this, &AMyActor::ProcessActorBeginOverlap);

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// 오버랩 체크 코드, 아래의 방식으로 사용하면 *OtherActor->GetName() 이 코드로 오버랩된 액터 이름을 가져올 수 있습니다.
	UE_LOG(LogTemp, Warning, TEXT("OtherActor : %s"), *OtherActor->GetName());
	//CPPToCallBP(10);	// 데미지 설정
	ExistCPPToCallBP(20);
}

void AMyActor::ExistCPPToCallBP_Implementation(int64 Damage)
{
	UE_LOG(LogTemp, Warning, TEXT("블루프린트 없으면 이거실행 %d"), Damage);
}

