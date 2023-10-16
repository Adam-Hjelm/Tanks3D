// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraSwapper.generated.h"

UCLASS()
class TANKS3D_API ACameraSwapper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraSwapper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	float TimeToNextCameraChange;

	UFUNCTION(BlueprintCallable, Category = "Camera")
	void SwitchCamera(AActor* CameraActor1, AActor* CameraActor2);

	//UPROPERTY(EditAnywhere)
	//AActor* CameraOne;

	//UPROPERTY(EditAnywhere)
	//AActor* CameraTwo;
};
