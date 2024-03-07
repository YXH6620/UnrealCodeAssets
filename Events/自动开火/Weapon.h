// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

//...

UCLASS()
class BLASTER_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	/**
	* Automatic fire
	*/
	// �Զ�������
	UPROPERTY(EditAnywhere, Category = Combat)
	float FireDelay = .15f;

	// �Զ����𿪹�
	UPROPERTY(EditAnywhere, Category = Combat)
	bool bAutomatic = true;

};