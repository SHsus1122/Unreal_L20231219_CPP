// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	// 아래의 작업은 우리가 MyGameModeBase 게임 모드 베이스를 사용하게 될 때,
	// 디폴트 폰을 AMyPawn 로 사용하고 컨트롤러도 MyPlayerController 디폴트로 사용한다는 의미입니다.
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
