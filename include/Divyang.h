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

using namespace std;

#ifndef DIVYANG_INC
#define DIVYANG_INC

template <typename T>
class DivyangNames;


class Divyang
{    
    const string divyangName_;
    struct Blind_ {};
    struct Ortho_ {};
    struct Cancer_ {};    
    struct Tb_ {};       
protected:
    Divyang(const string& divName) :divyangName_(divName) {}
    virtual ~Divyang() {}//Destructor

public:
    virtual double GetConcession(int BookingClassid) const = 0;
    inline string getDivyangName() const { return divyangName_; }
    typedef DivyangNames<Blind_> Blind;
    typedef DivyangNames<Ortho_> Ortho;
    typedef DivyangNames<Cancer_> Cancer;
    typedef DivyangNames<Tb_> Tb;   
    static bool UnitTestDivyang(); 
    friend ostream& operator<<(ostream& os,const Divyang & D);
};

#endif