// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

// 부득이하게 헤더에 선언하게 되었는데 이런경우 반드시 이 공간에 선언해주도록 합니다.
// GameFramework/Pawn.h 와 MyPawn.generated.h 사이에서 사용되게 해야합니다.
// 
// 이는 언리얼 엔진의 코드 생성도구(헤더툴)인 UHT(Unreal Header Tool)가 UCLASS 또는 USTRUCT 매크로가 있는 클래스 또는
// 구조체를 선언하는 헤더 파일의 끝에 자동으로 UHT 에 의해서 생성되는 코드입니다.
// 이후에는 해당 클래스 또는 구조체의 정의가 완료되었으며, 클래스 멤버들의 선언 및 정의가 이루어져야 합니다.
// 그래서 이 이후에 세부적인 내용의 추가를 위해서는 언리얼의 규칙을 따라야하며 해당 정의 이후에 코드를 추가해야합니다.
#include "InputActionValue.h"

#include "MyPawn.generated.h"

class UStaticMeshComponent;
class UArrowComponent;
class UBoxComponent;
class UCameraComponent;
class USpringArmComponent;
class UFloatingPawnMovement;
class UMyActorComponent;
class AMyActor;

// IA_Fire, IA_PitchAndRoll 과 같은 인풋 액션을 사용하기 위한 전방 선언입니다.
class UInputAction;

UCLASS()
class L20231219_CPP_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Left;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Right;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UFloatingPawnMovement> Movement;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UMyActorComponent> RotateComponent;

	// CDO 안의 오브젝트를 가리키는 방법입니다.
	// Rocket 에 해당하는 Actor 클래스인 AMyActor 타입으로 RocketTemplate 속성을 선언합니다.
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TSubclassOf<AMyActor> RoocketTemplate;

	// 발사 관련한 InputAction 와 움직임에 관한 InputAction 속성도 선언해줍니다.
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputAction> PitchAndRollAction;

	// 이제 이를 구현할 함수들을 선언해주는데, const 를 이용해서 값의 변경을 막아줍니다.
	// 아래의 인자들은 참조타입으로 선언되어있습니다.
	void Fire(const FInputActionValue& Value);

	void PitchAndRoll(const FInputActionValue& Value);
};
