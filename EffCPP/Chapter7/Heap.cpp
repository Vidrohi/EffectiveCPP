#include "Heap.h"

struct AllocHeader {
    int                             m_Size;
    MemoryManagement::Heap *        m_Heap;
};

void* MemoryManagement::Heap::Allocate(std::size_t size)
{
    size_t requestedBytes = size + sizeof(AllocHeader);
    char* memory = static_cast<char*>(malloc(requestedBytes));
    AllocHeader * allocationHeader = reinterpret_cast<AllocHeader*>(memory);
    allocationHeader->m_Heap = this;
    allocationHeader->m_Size = size;

    void * startingMemoryBlock = memory + sizeof(AllocHeader);
    return startingMemoryBlock;
}

void MemoryManagement::Heap::Deallocate(void* memoryAddress)
{
    void* actualAddress = static_cast<char*>(memoryAddress) - sizeof(AllocHeader);
    free(actualAddress);
}
