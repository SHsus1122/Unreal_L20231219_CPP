// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"

// SceneComponent 를 사용하기 위한 include 입니다.
#include "Components/SceneComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 매 Tick 마다 MyActorComponent 의 안에 담긴 모든 컴포넌트를 World 시간 기준으로 1000 의 속도로 회전시킵니다.
	for (auto Component : Components)
	{
		Component->AddLocalRotation(FRotator(0, 0, 1000.0f * DeltaTime));
	}
}

