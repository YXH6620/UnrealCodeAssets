void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ABlasterCharacter* BlasterCharacter = Cast<ABlasterCharacter>(OtherActor);
	// �ӵ���ײʱ�㲥
	if (BlasterCharacter)
	{
		BlasterCharacter->MulticastHit();
	}

	Destroy();
}