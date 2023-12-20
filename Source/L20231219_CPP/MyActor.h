// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class UProjectileMovementComponent;

UCLASS()
class L20231219_CPP_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UProjectileMovementComponent> Movement;

	// UFUNCTION() 은 함수 지정자 중 하나이며 언리얼 엔진에서 사용되는 매크로 입니다.
	// 이를 통해 함수의 특정 행동이나 속성을 정의하며 언리얼 엔진에 특정 기능을 활성화 할 수 있습니다.
	UFUNCTION()
	void ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	// C++ 에서 블루프린트 호출용으로 만든 함수
	// 아래의 UFUNCTION(BlueprintImplementableEvent) 를 만들면 생성자 없이 알아서 호출이 가능합니다.
	// 즉, C++ 에서의 바디 구현(함수 정의)은 하지 않아도 되어서 헤더파일에만 작성하고 사용이 가능합니다.
	UFUNCTION(BlueprintImplementableEvent)
	void CPPToCallBP(int64 Damage);

	// 위의 BlueprintNativeEvent 와는 다르게 C++ 로 함수의 바디 구현도 가능하면서 동시에
	// 블루프린트에서 오버라이드 C++ 을 그대로 호출하거나 새롭게 변경해서 호출도 가능합니다.
	// 기본 구현부분이 C++ 에 존재하므로 블루프린트에서 반드시 구현할 필요가 없습니다.
	// 단, 구현부 부분 함수명 뒤에 _Implementation 를 반드시 붙여주어야 합니다.
	UFUNCTION(BlueprintNativeEvent)
	void ExistCPPToCallBP(int64 Damage);
	void ExistCPPToCallBP_Implementation(int64 Damage);

};
