// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "WheeledVehicleTankPawn.generated.h"

/**
 * 
 */
UCLASS()
class TANKS3D_API AWheeledVehicleTankPawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Camera")
	void SwitchCamera(AActor* CameraActor1, AActor* CameraActor2);
	
};
