// Fill out your copyright notice in the Description page of Project Settings.


#include "WheeledVehicleTankPawn.h"
#include "Kismet/GameplayStatics.h"
//#include<array> We are already including this in the header file that is being included to this file

void AWheeledVehicleTankPawn::SwitchCamera(AActor* CameraOne, AActor* CameraTwo)
{
	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	//TimeToNextCameraChange -= DeltaTime;

	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController)
	{
		if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
		{
			// Cut instantly to camera one.
			OurPlayerController->SetViewTarget(CameraOne);
		}
		else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
		{
			// Blend smoothly to camera two.
			OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
		}
	}
}

TArray<FVector> AWheeledVehicleTankPawn::GetPositionsInTrajectory(float timeStep, FVector startVelocity, FVector startPos, float lineSegments, float gravityModifier)
{
	TArray<FVector> lineRendPoints; // if you want a fixed size array use TStaticArray
	lineRendPoints.SetNum(lineSegments);

	lineRendPoints[0] = startPos;

	for (int i = 1; i < lineSegments; i++)
	{
		float timeDiff = timeStep * i;

		FVector noGravityPosition = startVelocity * timeDiff;
		FVector gravityDiff = -0.5f * (9.82 * gravityModifier) * timeDiff * timeDiff * FVector::UpVector;
		FVector withGravityPosition = startPos + noGravityPosition + gravityDiff;
		lineRendPoints[i] = withGravityPosition;
	}

	return lineRendPoints;
}
//UE_LOG(LogTemp, Warning, FString::Printf(TEXT("GravityDiff: %f %f %f") gravityDiff.x, gravityDiff.y, gravityDiff.z)); /* Console Debug*/

//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,  /*Onscreen debug*/
//	FString::Printf(TEXT("Gravity Diff %f, %f, %f"), gravityDiff.X, gravityDiff.Y, gravityDiff.Z));