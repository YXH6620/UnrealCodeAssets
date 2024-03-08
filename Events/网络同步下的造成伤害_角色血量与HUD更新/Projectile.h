#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"
UCLASS()
class BLASTER_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	//...
	//  ÉËº¦ÊýÖµ
	UPROPERTY(EditAnywhere)
	float Damage = 20.f;

};