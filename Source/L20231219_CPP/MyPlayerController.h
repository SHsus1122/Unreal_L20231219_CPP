// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

// �Է� �׼��� ����ϱ� ���� ���� ����
class UInputMappingContext;

UCLASS()
class L20231219_CPP_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// ���۽� ���� �Է��� ����ϱ� ���ؼ� BeginPlay �� override �ؼ� ������ �� �غ� �մϴ�.
	virtual void BeginPlay() override;

	// ���� �Է��� ����ϱ� ���ؼ� �Ʒ�ó�� UInputMappingContext Ÿ�� ��� ������ �����մϴ�.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> InputContext;
};
