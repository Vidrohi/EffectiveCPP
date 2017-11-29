#include <string>

#include "gtest/gtest.h"
#include "../EffCPP/Chapter6/NonPOD.h"

#include <iostream>
#include <stdio.h>
#include <iomanip> 

namespace {
    TEST(SilentConstructions, VectorTests) {

        printf("***************[VECTOR TESTS]*****************\n");
        // Calls NonPOD(const std::string& name)
        Performance::NonPOD constructedWithName(std::string("CONSTRUCTED_WITH_NAME"));
        printf("**********************************************\n");
        printf("**********************************************\n");
        printf("**********************************************\n");

        std::vector<Performance::NonPOD> nonPodVect;

        // Calls the copy constructor (and then whatever the vector does)
        nonPodVect.push_back(constructedWithName);
        printf("**********************************************\n");

        // Constructs the nonpod config
        // Then constructs the non pod
        // Copy constructs from this nonpod into the vector
        // Copy constructs the element already in there (resizing of the vector I imagine)
        nonPodVect.push_back(Performance::NonPODConfig(32.0));
        printf("**********************************************\n");

        // Constructs the new NonPOD
        // Copy constructs the new NonPOD
        // Copy constructs both of the other elements as well ! (vector resizing ?)
        nonPodVect.push_back(Performance::NonPOD("Messing_With_vector"));
        printf("**********************************************\n");

        printf("*************[RESERVED 6 ELT]*****************\n");
        // Reserves space for 6 elements
        nonPodVect.reserve(6);
        printf("**********************************************\n");

        // Copy constructs pre existing elements
        // Constructs a new NonPOD
        // Copy constructs the new NonPOD
        nonPodVect.push_back(Performance::NonPOD("VectorElt4"));
        printf("**********************************************\n");

        // Constructs a new NonPOD
        // Copy constructs Only that element
        nonPodVect.push_back(Performance::NonPOD("VectorElt5"));
        printf("**********************************************\n");

        // Constructs a new NonPOD
        // Copy constructs Only that element
        nonPodVect.push_back(Performance::NonPOD("VectorElt6"));
        printf("**********************************************\n");

        // Constructs a new NonPOD
        // Copy constructs that element
        // Copy constructs every pre existing element
        nonPodVect.push_back(Performance::NonPOD("VectorElt7"));
        printf("**********************************************\n");

        getchar();
    }
}