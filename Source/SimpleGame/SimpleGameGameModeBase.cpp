#include "SimpleGameGameModeBase.h"
#include "SimplePlayerPawn.h"

ASimpleGameGameModeBase::ASimpleGameGameModeBase()
{
    DefaultPawnClass = ASimplePlayerPawn::StaticClass();
}
