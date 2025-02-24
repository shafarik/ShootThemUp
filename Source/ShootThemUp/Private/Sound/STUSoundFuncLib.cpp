// Shoot Them Up Game, All Rights Reserved.


#include "Sound/STUSoundFuncLib.h"
#include "Sound/SoundClass.h"
DEFINE_LOG_CATEGORY_STATIC(LogSoundFunclib,All,All);

void USTUSoundFuncLib::SetSoundClassVolume(USoundClass* SoundClass, float Volume)
{
    if (!SoundClass)return;

    SoundClass->Properties.Volume=FMath::Clamp(Volume,0.0f,1.0f);
    UE_LOG(LogSoundFunclib, Display, TEXT("Souind class volume was changed: %s = %f"), *SoundClass->GetName(),
           SoundClass->Properties.Volume);
}

void USTUSoundFuncLib::ToggleSoundClassVolume(USoundClass* SoundClass)
{
    if (!SoundClass)
        return;

       const auto NextVolume=SoundClass->Properties.Volume>0.0f?0.0f:1.0f;
    SetSoundClassVolume(SoundClass,NextVolume);
}
