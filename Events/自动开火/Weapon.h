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
	// 自动开火间隔
	UPROPERTY(EditAnywhere, Category = Combat)
	float FireDelay = .15f;

	// 自动开火开关
	UPROPERTY(EditAnywhere, Category = Combat)
	bool bAutomatic = true;

};