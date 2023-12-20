// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"

// SceneComponent 를 사용하기 위한 전방선언 입니다.
class USceneComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class L20231219_CPP_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Componet 를 담기 위해서 배열(TArray)를 사용할건데, 이 배열에 여러 종류의 컴포넌트가 담길 수 있습니다.
	// 그래서 해당 배열의 타입을 대부분의 형식을 다 담을 수 있는 SceneComponent 로 지정합니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	TArray<TObjectPtr<USceneComponent>> Components;
};
