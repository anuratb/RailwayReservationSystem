/**
 * @file category.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief Category Types of Passenger Abstract Base Class
 * @version 0.2
 * @date 2021-03-25
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include "Divyang.h"
using namespace std;

#ifndef DIVYANGNM_INC
#define DIVYANGNM_INC
template <typename T>
class DivyangNames : public Divyang
{
    static const string sDivyangName;
    static const vector<double> sDivyangCons;                                         //To store divyang concessions
    inline DivyangNames(string nme = DivyangNames<T>::sDivyangName) : Divyang(nme) {} //Cr
    virtual ~DivyangNames(){};                                                        //Destructor
    

public:
    inline double GetConcession(int BookingClassid) const { return DivyangNames<T>::sDivyangCons[BookingClassid]; }
    static bool UnitTestingDivyangNames();
    static const DivyangNames<T> &Type() //To return Singleton
    {
        static const DivyangNames<T> Obj;
        return Obj;
    }
};

#endif