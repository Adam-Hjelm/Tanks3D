// Fill out your copyright notice in the Description page of Project Settings.


#include "WheeledVehicleTankPawn.h"
#include "Kismet/GameplayStatics.h"

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