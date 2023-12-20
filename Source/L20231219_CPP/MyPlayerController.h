// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

// 입력 액션을 사용하기 위한 전방 선언
class UInputMappingContext;

UCLASS()
class L20231219_CPP_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// 시작시 향상된 입력을 사용하기 위해서 BeginPlay 를 override 해서 재정의 할 준비를 합니다.
	virtual void BeginPlay() override;

	// 향상된 입력을 사용하기 위해서 아래처럼 UInputMappingContext 타입 멤버 변수를 정의합니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> InputContext;
};
