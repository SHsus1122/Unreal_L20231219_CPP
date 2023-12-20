// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"

// SceneComponent �� ����ϱ� ���� include �Դϴ�.
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

	// �� Tick ���� MyActorComponent �� �ȿ� ��� ��� ������Ʈ�� World �ð� �������� 1000 �� �ӵ��� ȸ����ŵ�ϴ�.
	for (auto Component : Components)
	{
		Component->AddLocalRotation(FRotator(0, 0, 1000.0f * DeltaTime));
	}
}

