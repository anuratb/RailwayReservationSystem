/**
 * @file testapp.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief TestApplication Header
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include<fstream>
#include <sstream>
#include <iostream>
using namespace std;
#include "../include/booking.h"
#include "../include/bookingname.h"
#ifndef TEST_INC
#define TEST_INC
class TestApplication
{
    int unitTests_;
    int unitTestsPassed_;
    int tests_;
    int testsPassed_;
    //  Blocked Copy constructor
    TestApplication(const TestApplication &other);
    // Blocked Copy Assignment Operator
    TestApplication &operator=(const TestApplication &other);

public:
    TestApplication(); //Constructor    
};
#endif