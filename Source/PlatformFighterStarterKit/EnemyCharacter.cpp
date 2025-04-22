#include "EnemyCharacter.h"
#include "EnemyAIController.h"

AEnemyCharacter::AEnemyCharacter()
{
    AIControllerClass = AEnemyAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}
