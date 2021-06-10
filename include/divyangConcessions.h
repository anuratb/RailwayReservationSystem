/**
 * @file divyangConcessions.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief Divyang Concession
 * @version 0.1
 * @date 2021-04-09
 *  
 */
#include <iostream>
#include "concessions.h"
#include "passenger.h"
#include "DivyangNames.h"
#include "bookingClassNames.h"
using namespace std;
#ifndef DIVYANG_CONS_INC
#define DIVYANG_CONS_INC
class DivyangConcession :public Concessions
{
    public:
    DivyangConcession(const Passenger& P,const BookingClass & B) ;
    static bool  UnitTestDivyangConcession();
    ~DivyangConcession();
};
#endif