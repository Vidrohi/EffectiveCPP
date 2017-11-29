#include "NonPOD.h"

unsigned int Performance::NonPOD::s_currentId = 0;

unsigned int Performance::NonPOD::GetNextId()
{
    return ++s_currentId;
}