// Tests.cpp : Defines the entry point for the console application.
//

#include <string>

#include "stdafx.h"
#include "gtest/gtest.h"
#include "../EffCPP/Chapter6/NonPOD.h"

#include <iostream>
#include <stdio.h>
#include <iomanip> 

using namespace std;

namespace {

    void PrintNonPODByVal(Performance::NonPOD values)
    {
        printf("[PRINT_PASS_BY_VALUE] , NonPOD %s with id %i and value %f was printed \n", values.GetName().c_str(), values.GetId(), values.GetValue());
    }

    void PrintNonPODConstRef(const Performance::NonPOD& values)
    {
        printf("[PRINT_PASS_BY_REF] , NonPOD %s with id %i and value %f was printed \n", values.GetName().c_str(), values.GetId(), values.GetValue());
    }


    TEST(SilentConstructions, StandardConstructors) {
        // Only default constructor
        Performance::NonPOD defaultConstructed;
        printf("**********************************************\n");

        // Calls NonPOD(const std::string& name)
        Performance::NonPOD constructedWithName(std::string("CONSTRUCTED_WITH_NAME"));
        printf("**********************************************\n");
    }

    TEST(SilentConstructions, PromotedConstruction) {
        // Calls NonPOD(const std::string& name)
        Performance::NonPOD constructedWithCstrPromotion("CONSTRUCTED_WITH_C_STR_PROMOTION");
        printf("**********************************************\n");

        // Promotes a float to a config and constructs
        Performance::NonPOD constructedWithFloatPromotedToConfig(7.0f);
        printf("**********************************************\n");
    }

    TEST(SilentConstructions, PassByValueAndRef) {

        // Calls NonPOD(const std::string& name)
        Performance::NonPOD printMe(std::string("PRINT_ME"));
        printf("**********************************************\n");
        printf("**********************************************\n");
        printf("**********************************************\n");

        // Copy constructs a NonPOD object and then calls the Print method
        PrintNonPODByVal(printMe);
        printf("**********************************************\n");

        // Directly calls the print method on a reference to the passed object
        PrintNonPODConstRef(printMe);
        printf("**********************************************\n");
    }

    TEST(SilentConstructions, Assignment) {

        // Calls NonPOD(const std::string& name)
        Performance::NonPOD constructedWithName(std::string("CONSTRUCTED_WITH_NAME"));
        printf("**********************************************\n");

        // Promotes a float to a config and constructs
        Performance::NonPOD constructedWithFloatPromotedToConfig(7.0f);
        printf("**********************************************\n");
        printf("**********************************************\n");
        printf("**********************************************\n");

        // Calls the assignment operator only
        constructedWithFloatPromotedToConfig = constructedWithName;
        printf("**********************************************\n");

        // Constructs a NonPODConfig object, Promotes it to a NonPOD object and then calls the assignment operator
        constructedWithFloatPromotedToConfig = Performance::NonPODConfig(15.0f);
        printf("**********************************************\n");
    }
}

