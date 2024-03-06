// Fill out your copyright notice in the Description page of Project Settings.
#include "CombatComponent.h"
#include "Blaster/Weapon/Weapon.h"
#include "Blaster/Character/BlasterCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCombatComponent, EquippedWeapon);
	// 要同步的状态bool变量
	DOREPLIFETIME(UCombatComponent, bAiming);
}

void UCombatComponent::FireButtonPressed(bool bPressed)
{
	bFireButtonPressed = bPressed;
	if (bFireButtonPressed)
	{
		// C->S
		ServerFire();
	}
}

void UCombatComponent::ServerFire_Implementation()
{
	//S->CCCCCC
	MulticastFire();
}

// 服务端广播
void UCombatComponent::MulticastFire_Implementation()
{
	if (EquippedWeapon == nullptr) return;
	if (Character)
	{
		Character->PlayFireMontage(bAiming);
		EquippedWeapon->Fire();
	}
}