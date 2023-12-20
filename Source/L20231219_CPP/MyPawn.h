// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

// �ε����ϰ� ����� �����ϰ� �Ǿ��µ� �̷���� �ݵ�� �� ������ �������ֵ��� �մϴ�.
// GameFramework/Pawn.h �� MyPawn.generated.h ���̿��� ���ǰ� �ؾ��մϴ�.
// 
// �̴� �𸮾� ������ �ڵ� ��������(�����)�� UHT(Unreal Header Tool)�� UCLASS �Ǵ� USTRUCT ��ũ�ΰ� �ִ� Ŭ���� �Ǵ�
// ����ü�� �����ϴ� ��� ������ ���� �ڵ����� UHT �� ���ؼ� �����Ǵ� �ڵ��Դϴ�.
// ���Ŀ��� �ش� Ŭ���� �Ǵ� ����ü�� ���ǰ� �Ϸ�Ǿ�����, Ŭ���� ������� ���� �� ���ǰ� �̷������ �մϴ�.
// �׷��� �� ���Ŀ� �������� ������ �߰��� ���ؼ��� �𸮾��� ��Ģ�� ������ϸ� �ش� ���� ���Ŀ� �ڵ带 �߰��ؾ��մϴ�.
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

// IA_Fire, IA_PitchAndRoll �� ���� ��ǲ �׼��� ����ϱ� ���� ���� �����Դϴ�.
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

	// CDO ���� ������Ʈ�� ����Ű�� ����Դϴ�.
	// Rocket �� �ش��ϴ� Actor Ŭ������ AMyActor Ÿ������ RocketTemplate �Ӽ��� �����մϴ�.
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TSubclassOf<AMyActor> RoocketTemplate;

	// �߻� ������ InputAction �� �����ӿ� ���� InputAction �Ӽ��� �������ݴϴ�.
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputAction> PitchAndRollAction;

	// ���� �̸� ������ �Լ����� �������ִµ�, const �� �̿��ؼ� ���� ������ �����ݴϴ�.
	// �Ʒ��� ���ڵ��� ����Ÿ������ ����Ǿ��ֽ��ϴ�.
	void Fire(const FInputActionValue& Value);

	void PitchAndRoll(const FInputActionValue& Value);
};
