// EffCPP.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "..\Chapter2\SilentFunctions.h"
#include "..\Chapter6\PerformanceTester.h"

class DumberDataType
{
public:
    DumberDataType()
    {
        i = new int;
    }

private:
    int * i;

};

class DumbDataType
{
    DumberDataType ddt;
    //std::string m_name;
};

int main()
{
    printf("STARTING MEMORY MANAGEMENT TESTING \n");

    printf("******************* Creating DATA ******************* \n");
    DumbDataType* data = new DumbDataType();
    //std::string* data;
    //data = new std::string();
    //delete data;

    //printf("******************* Creating LORE ******************* \n");
    //DumbDataType * lore = new DumbDataType();
    //delete lore;


    getchar();
}

