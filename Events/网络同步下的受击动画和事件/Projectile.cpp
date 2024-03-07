void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ABlasterCharacter* BlasterCharacter = Cast<ABlasterCharacter>(OtherActor);
	// ×Óµ¯Åö×²Ê±¹ã²¥
	if (BlasterCharacter)
	{
		BlasterCharacter->MulticastHit();
	}

	Destroy();
}