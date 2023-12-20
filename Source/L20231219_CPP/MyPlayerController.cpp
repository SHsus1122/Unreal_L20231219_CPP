// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

// 향상된 입력을 사용하기 위해서 include 해줍니다.
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void AMyPlayerController::BeginPlay()
{
	// 부모의 기능을 상속받아서 구현
	Super::BeginPlay();

	// 향상된 입력(EnhancedInput) 플러그인을 사용해 로컬 서브 시스템을 정의합니다.
	// 이 코드는 향상된 입력에서 제공하는 서브시스템을 얻어서 사용자가 해당 플러그인의 기능을 활용할 준비를 합니다.
	UEnhancedInputLocalPlayerSubsystem* SubSystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	// 입력 시스템이 여러개 있을 수 있는데 그 중에서 원하는것을 가져오기 위한 작업입니다.
	// 여기서 가져온것이 null 이면 안되기 때문에 아래처럼 if 문으로 조건문 안에 코드를 넣어줍니다.
	if (SubSystem && InputContext)
	{
		// AddMappingContext 안의 옵션은 어떤 입력 시스템(InputMappingContext)를 선택할지에 대한 것입니다.
		// 즉, 여러개의 입력 시스템이 있을 수 있는데 이중에 어떤 것을 우선순위에 의해서 고를지에 대한 인덱스 번호입니다.
		SubSystem->AddMappingContext(InputContext, 0);
	}
}