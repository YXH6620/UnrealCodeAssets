// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"
UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()
public:

	virtual void PostInitializeComponents() override;
protected:

	//...
	// 按E时碰撞事件绑定的回调函数
	void EquipButtonPressed();

private:
	// 组合
	UPROPERTY(VisibleAnywhere)
	class UCombatComponent* Combat;

	// RPC：客户端调用，在服务器执行。是可靠的
	UFUNCTION(Server, Reliable)
	void ServerEquipButtonPressed();

public:
	void SetOverlappingWeapon(AWeapon* Weapon);
	// 判断是否装备武器
	bool IsWeaponEquipped();
};