#include <assert.h>
#include "MemoryManager.h"
#include "HeapFactory.h"
#include <stdio.h>

void * operator new(std::size_t size, MemoryManagement::Heap* heap)
{
    assert(heap != nullptr);
    assert(size > 0);
    return heap->Allocate(size);
}

void * operator new(std::size_t size)
{
    printf("[New] %i \n", size);
    return operator new (size, MemoryManagement::HeapFactory::GetDefaultHeap());
}

void operator delete (void * memoryLocation)
{
    if (memoryLocation != NULL)
    {
        printf("[Delete] %p \n", memoryLocation);
        MemoryManagement::Heap::Deallocate(memoryLocation);
    }
}