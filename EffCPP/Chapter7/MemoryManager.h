#pragma once
#include <cstddef>

namespace MemoryManagement
{
    class Heap;
}

void * operator new (std::size_t size, MemoryManagement::Heap* heap);
