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
	// ��Eʱ��ײ�¼��󶨵Ļص�����
	void EquipButtonPressed();

private:
	// ���
	UPROPERTY(VisibleAnywhere)
	class UCombatComponent* Combat;

	// RPC���ͻ��˵��ã��ڷ�����ִ�С��ǿɿ���
	UFUNCTION(Server, Reliable)
	void ServerEquipButtonPressed();

public:
	void SetOverlappingWeapon(AWeapon* Weapon);
	// �ж��Ƿ�װ������
	bool IsWeaponEquipped();
};