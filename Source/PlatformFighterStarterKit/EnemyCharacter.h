#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class PLATFORMFIGHTERSTARTERKIT_API AEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemyCharacter();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TArray<AActor*> PatrolPoints;
};
