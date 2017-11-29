#include "HeapFactory.h"

MemoryManagement::Heap* MemoryManagement::HeapFactory::s_defaultHeap = nullptr;
MemoryManagement::Heap MemoryManagement::HeapFactory::s_heaps[];

MemoryManagement::Heap* MemoryManagement::HeapFactory::GetDefaultHeap()
{
    if (s_defaultHeap == nullptr)
    {
        Initialize();
    }

    return s_defaultHeap;
}

void MemoryManagement::HeapFactory::Initialize()
{
    const char* name = { "DefaultHeap" };
    s_heaps[0].SetName(name);
    s_defaultHeap = &(s_heaps[0]);
}

