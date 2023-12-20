// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	// �Ʒ��� �۾��� �츮�� MyGameModeBase ���� ��� ���̽��� ����ϰ� �� ��,
	// ����Ʈ ���� AMyPawn �� ����ϰ� ��Ʈ�ѷ��� MyPlayerController ����Ʈ�� ����Ѵٴ� �ǹ��Դϴ�.
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
