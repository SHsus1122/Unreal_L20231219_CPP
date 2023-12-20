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

	// UFUNCTION() �� �Լ� ������ �� �ϳ��̸� �𸮾� �������� ���Ǵ� ��ũ�� �Դϴ�.
	// �̸� ���� �Լ��� Ư�� �ൿ�̳� �Ӽ��� �����ϸ� �𸮾� ������ Ư�� ����� Ȱ��ȭ �� �� �ֽ��ϴ�.
	UFUNCTION()
	void ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	// C++ ���� �������Ʈ ȣ������� ���� �Լ�
	// �Ʒ��� UFUNCTION(BlueprintImplementableEvent) �� ����� ������ ���� �˾Ƽ� ȣ���� �����մϴ�.
	// ��, C++ ������ �ٵ� ����(�Լ� ����)�� ���� �ʾƵ� �Ǿ ������Ͽ��� �ۼ��ϰ� ����� �����մϴ�.
	UFUNCTION(BlueprintImplementableEvent)
	void CPPToCallBP(int64 Damage);

	// ���� BlueprintNativeEvent �ʹ� �ٸ��� C++ �� �Լ��� �ٵ� ������ �����ϸ鼭 ���ÿ�
	// �������Ʈ���� �������̵� C++ �� �״�� ȣ���ϰų� ���Ӱ� �����ؼ� ȣ�⵵ �����մϴ�.
	// �⺻ �����κ��� C++ �� �����ϹǷ� �������Ʈ���� �ݵ�� ������ �ʿ䰡 �����ϴ�.
	// ��, ������ �κ� �Լ��� �ڿ� _Implementation �� �ݵ�� �ٿ��־�� �մϴ�.
	UFUNCTION(BlueprintNativeEvent)
	void ExistCPPToCallBP(int64 Damage);
	void ExistCPPToCallBP_Implementation(int64 Damage);

};
