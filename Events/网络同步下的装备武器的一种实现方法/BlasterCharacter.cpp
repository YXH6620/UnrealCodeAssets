// Fill out your copyright notice in the Description page of Project Settings.
#include "BlasterCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"
#include "Blaster/Weapon/Weapon.h"
#include "Blaster/BlasterComponents/CombatComponent.h"

ABlasterCharacter::ABlasterCharacter()
{
	//...

	Combat = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	// CombatComponent需要网络复制
	Combat->SetIsReplicated(true);
}

void ABlasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//...
	// 绑定回调函数
	PlayerInputComponent->BindAction("Equip", IE_Pressed, this, &ABlasterCharacter::EquipButtonPressed);
}

void ABlasterCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (Combat)
	{
		Combat->Character = this;
	}
}

// 回调函数
void ABlasterCharacter::EquipButtonPressed()
{
	if (Combat)
	{
		// Server端
		if (HasAuthority())
		{
			Combat->EquipWeapon(OverlappingWeapon);
		}
		// Client端。RPC调用后在Server执行，然后发送到每个客户端
		else
		{
			ServerEquipButtonPressed();
		}
	}
}

void ABlasterCharacter::ServerEquipButtonPressed_Implementation()
{
	if (Combat)
	{
		Combat->EquipWeapon(OverlappingWeapon);
	}
}

bool ABlasterCharacter::IsWeaponEquipped()
{
	return (Combat && Combat->EquippedWeapon);
}
