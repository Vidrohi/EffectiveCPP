#pragma once

/*
* In any class , The compiler silently adds a number of functions ONLY when it needs them.
* These functions include :
* Default constructor
    Only if the class has no constructor

* Copy constructor
    Does shallow by value copies of all non static data members
* Assignment operator
    Copy by value using the assignment operator instead of a constructor

    IMPORTANT : If all non static data members are not copyable (being consted or being a reference or some other new fangled thing) then the compilation of the code fails unless you manually provide an override that can deal with the situation.

* Destructor
    Is virtual if this class derives from another base class that has a virtual destructor

    If you want to explicittly disallow one of these operations on certain objects then you can declare these functions as private in your class (but not define them). This way, when someone tried to call these functions they get a linker error
*/

// Example
class Empty
{
    /*
    This class seems empty but the compiler silently adds the following when needed 
    */

    /*
    public:
        Empty(){}

        Empty(const Empty& rhs){}

        Empty& operator=(const Empty& rhs);

        ~Empty();
    */
};

class CopyTest
{
public:
    int value;
    const int value2;

    CopyTest()
        :value2(12)
    {}

    CopyTest& operator=(const CopyTest& rhs)
    {
        value = rhs.value;

        return *this;
    }
};

class CopyTester
{
    CopyTest ct1;

public:

    void InitializeTest()
    {
        ct1.value = 10;
    }

    void RunTest()
    {
        //CopyTest ct2(ct1);
        CopyTest ct3;
        ct3.value = 20;
        ct3 = ct1;

        std::cout << "Copy Test 1 Value " << ct1.value << '\n';
        //std::cout << "Copy Test 2 Value " << ct2.value2 << '\n';
        std::cout << "Copy Test 3 Value " << ct3.value2 << '\n';
    }
};