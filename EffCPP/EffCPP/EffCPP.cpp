// EffCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "..\Chapter2\SilentFunctions.h"
#include "..\Chapter6\PerformanceTester.h"

//namespace {
//// Tests factorial of 0.
//TEST("Basic_Test","Test") {
//        EXPECT_EQ(1, 1);
//    }
//}

int main()
{
    Performance::Tester::RunTest();

    getchar();
    return 0;
}

