#include <string>
#include "gtest/gtest.h"
#include <iostream>
#include <stdio.h>
#include <iomanip> 


namespace {

    class DumbDataType
    {
        int m_value;
        std::string m_name;
    };

    TEST(MemoryManagement, Construction) {
        printf("STARTING MEMORY MANAGEMENT TESTING \n");

        DumbDataType * lore = new DumbDataType();
        delete lore;

        getchar();
    }
}