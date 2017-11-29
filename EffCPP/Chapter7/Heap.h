#pragma once
#include <string.h>
#include <exception>
#include <string>

namespace MemoryManagement
{
    class Heap
    {
    public:
        Heap() {}
        Heap(const char* heapName)
        {
            strcpy_s(m_name, heapName);
        }

        inline void SetName(const char* name)
        {
            strcpy_s(m_name, name);
        }

        inline const char * GetName() const { return m_name; }

        void* Allocate(std::size_t size);
        static void Deallocate(void* memoryAddress);

    private:

        enum { NAMELENGTH = 256 };
        char m_name[NAMELENGTH];
    };
}