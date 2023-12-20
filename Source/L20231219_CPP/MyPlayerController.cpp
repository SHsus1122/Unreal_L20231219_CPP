// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

// ���� �Է��� ����ϱ� ���ؼ� include ���ݴϴ�.
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void AMyPlayerController::BeginPlay()
{
	// �θ��� ����� ��ӹ޾Ƽ� ����
	Super::BeginPlay();

	// ���� �Է�(EnhancedInput) �÷������� ����� ���� ���� �ý����� �����մϴ�.
	// �� �ڵ�� ���� �Է¿��� �����ϴ� ����ý����� �� ����ڰ� �ش� �÷������� ����� Ȱ���� �غ� �մϴ�.
	UEnhancedInputLocalPlayerSubsystem* SubSystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	// �Է� �ý����� ������ ���� �� �ִµ� �� �߿��� ���ϴ°��� �������� ���� �۾��Դϴ�.
	// ���⼭ �����°��� null �̸� �ȵǱ� ������ �Ʒ�ó�� if ������ ���ǹ� �ȿ� �ڵ带 �־��ݴϴ�.
	if (SubSystem && InputContext)
	{
		// AddMappingContext ���� �ɼ��� � �Է� �ý���(InputMappingContext)�� ���������� ���� ���Դϴ�.
		// ��, �������� �Է� �ý����� ���� �� �ִµ� ���߿� � ���� �켱������ ���ؼ� ������ ���� �ε��� ��ȣ�Դϴ�.
		SubSystem->AddMappingContext(InputContext, 0);
	}
}