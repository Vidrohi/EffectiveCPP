#pragma once
#include "Heap.h"

namespace MemoryManagement
{
    class HeapFactory
    {
    public:
        static Heap* GetDefaultHeap();

    private:
        static void Initialize();

        enum { MAXHEAPS = 1 };

        static Heap* s_defaultHeap;
        static Heap s_heaps[MAXHEAPS];
    };
}
