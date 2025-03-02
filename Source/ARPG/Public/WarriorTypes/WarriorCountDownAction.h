// HS

#pragma once

#include "CoreMinimal.h"
#include "WarriorEnumTypes.h"

class FWarriorCountDownAction : public FPendingLatentAction
{
	public:
	FWarriorCountDownAction(float InTotalCountDownTime, float InUpdateInterval, float& InOutRemainingTime,
	                        EWarriorCountDownActionOutput& InCountDownOutput, const FLatentActionInfo& LatentInfo)
		                        : bNeedToCancel(false), TotalCountDownTime(InTotalCountDownTime),
		                          OutRemainingTime(InOutRemainingTime), CountDownOutput(InCountDownOutput),
		                          ExecutionFunction(LatentInfo.ExecutionFunction), OutputLink(LatentInfo.Linkage),
		                          CallbackTarget(LatentInfo.CallbackTarget), ElapsedInterval(0.f),
		                          ElapsedTimeSinceStart(0.f)
	{
	}

	void CancelAction();

private:
	bool bNeedToCancel;             // 카운트다운을 취소해야 하는지 여부를 나타내는 플래그
	float TotalCountDownTime;       // 카운트다운이 실행되어야 하는 총 시간
	float UpdateInterval;           // 카운트다운을 얼마나 자주 업데이트/틱할지 (예: 0.1초마다)
	float& OutRemainingTime;        // 남은 시간을 저장하고 출력하기 위한 참조 (외부에서 접근 가능)
	EWarriorCountDownActionOutput& CountDownOutput;  // 카운트다운 상태/출력을 추적하기 위한 열거형 참조
	FName ExecutionFunction;        // 완료 시 실행할 블루프린트 함수의 이름
	int32 OutputLink;               // 블루프린트 그래프에서 출력 핀의 인덱스
	FWeakObjectPtr CallbackTarget;  // 실행 함수를 소유한 객체에 대한 약한 포인터
	float ElapsedInterval;          // 마지막 간격 업데이트 이후 누적된 시간
	float ElapsedTimeSinceStart;    // 카운트다운 시작 이후 경과한 총 시간
};
