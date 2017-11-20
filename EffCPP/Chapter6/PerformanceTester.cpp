#include "stdafx.h"
#include "NonPOD.h"
#include "PerformanceTester.h"

#include <vector>

void PrintNonPODByVal(Performance::NonPOD values)
{
    printf("[PRINT_PASS_BY_VALUE] , NonPOD %s with id %i and value %f was printed \n", values.GetName().c_str(), values.GetId(), values.GetValue());
}

void PrintNonPODConstRef(const Performance::NonPOD& values)
{
    printf("[PRINT_PASS_BY_REF] , NonPOD %s with id %i and value %f was printed \n", values.GetName().c_str(), values.GetId(), values.GetValue());
}

void Performance::Tester::RunTest()
{
    // Only default constructor
    NonPOD defaultConstructed;
    printf("**********************************************\n");

    // Calls NonPOD(const std::string& name)
    NonPOD constructedWithName(std::string("CONSTRUCTED_WITH_NAME"));
    printf("**********************************************\n");

    // Calls NonPOD(const std::string& name)
    NonPOD constructedWithCstrPromotion("CONSTRUCTED_WITH_C_STR_PROMOTION");
    printf("**********************************************\n");

    // Promotes a float to a config and constructs
    NonPOD constructedWithFloatPromotedToConfig(7.0f);
    printf("**********************************************\n");

    // Copy constructs a NonPOD object and then calls the Print method
    PrintNonPODByVal(constructedWithName);
    printf("**********************************************\n");

    // Directly calls the print method on a reference to the passed object
    PrintNonPODConstRef(constructedWithName);
    printf("**********************************************\n");

    // Calls only the set value method
    constructedWithName.SetValue(10.0f);
    printf("**********************************************\n");

    // Calls the assignment operator only
    constructedWithFloatPromotedToConfig = constructedWithName;
    printf("**********************************************\n");

    // Constructs a NonPODConfig object, Promotes it to a NonPOD object and then calls the assignment operator
    constructedWithFloatPromotedToConfig = NonPODConfig(15.0f);
    printf("**********************************************\n");

    printf("***************[VECTOR TESTS]*****************\n");
    std::vector<NonPOD> nonPodVect;

    // Calls the copy constructor (and then whatever the vector does)
    nonPodVect.push_back(constructedWithName);
    printf("**********************************************\n");
    
    // Constructs the nonpod config
    // Then constructs the non pod
    // Copy constructs from this nonpod into the vector
    // Copy constructs the element already in there (resizing of the vector I imagine)
    nonPodVect.push_back(NonPODConfig(32.0));
    printf("**********************************************\n");

    // Constructs the new NonPOD
    // Copy constructs the new NonPOD
    // Copy constructs both of the other elements as well ! (vector resizing ?)
    nonPodVect.push_back(NonPOD("Messing_With_vector"));
    printf("**********************************************\n");

    printf("*************[RESERVED 6 ELT]*****************\n");
    // Reserves space for 6 elements
    nonPodVect.reserve(6);

    // Copy constructs pre existing elements
    // Constructs a new NonPOD
    // Copy constructs the new NonPOD
    nonPodVect.push_back(NonPOD("VectorElt4"));
    printf("**********************************************\n");

    // Constructs a new NonPOD
    // Copy constructs Only that element
    nonPodVect.push_back(NonPOD("VectorElt5"));
    printf("**********************************************\n");

    // Constructs a new NonPOD
    // Copy constructs Only that element
    nonPodVect.push_back(NonPOD("VectorElt6"));
    printf("**********************************************\n");

    // Constructs a new NonPOD
    // Copy constructs that element
    // Copy constructs every pre existing element
    nonPodVect.push_back(NonPOD("VectorElt7"));
    printf("**********************************************\n");
}