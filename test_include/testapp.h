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
class TestTotalApplication
{
 
    //  Blocked Copy constructor
    TestTotalApplication(const TestTotalApplication &other);
    // Blocked Copy Assignment Operator
    TestTotalApplication &operator=(const TestTotalApplication &other);

public:
    TestTotalApplication(); //Constructor    
};
#endif