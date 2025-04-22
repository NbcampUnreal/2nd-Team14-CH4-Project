#include "EnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "EnemyCharacter.h"

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
    MoveToCurrentPatrolPoint();
}

void AEnemyAIController::MoveToCurrentPatrolPoint()
{
    AEnemyCharacter* MyEnemyChar = Cast<AEnemyCharacter>(GetPawn());

    if (!MyEnemyChar || MyEnemyChar->PatrolPoints.Num() == 0)
        return;

    MoveToActor(
        MyEnemyChar->PatrolPoints[CurrentPatrolIndex],
        5.0f,
        true,
        true,
        false,
        nullptr,
        true
    );

    CurrentPatrolIndex = (CurrentPatrolIndex + 1) % MyEnemyChar->PatrolPoints.Num();
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    Super::OnMoveCompleted(RequestID, Result);

    if (Result.Code == EPathFollowingResult::Success)
    {
        MoveToCurrentPatrolPoint();
    }
}
