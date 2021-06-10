/**
 * @file bookingclass.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief Abstract Base Class Booking Class
 * @version 0.1
 * @date 2021-03-06
 *
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;
#ifndef BOOKINGCLASS_INC
#define BOOKINGCLASS_INC

template <typename T>
class BookingClassNames;

class BookingClass
{
private:
    struct AC2Tier_
    {
    };
    struct AC3Tier_
    {
    };
    struct ACChairCar_
    {
    };
    struct ACFirstClass_
    {
    };
    struct ExecutiveChairCar_
    {
    };
    struct FirstClass_
    {
    };
    struct Sleeper_
    {
    };
    struct SecondSitting_
    {
    };
    BookingClass(const BookingClass &other);       //CCR
    BookingClass &operator=(const BookingClass &); //CAO
    const string name_;
    const int id_;
protected:
    virtual ~BookingClass();  //Virtual Destructor
    BookingClass(string nme,int id); //Constructor

public:
    /*
    static double sLoadFactor;
    static double sTatkalLoadFactor;
    static double sMinTatkalCharge;
    static double sMaxTatkalCharge;
    static double sMinTatkalDistance;
    */
    virtual int GetClassId() const =0;
    virtual string GetName() const = 0;                               //To get name
    virtual double GetLoadFactor() const = 0;                         //To Get Load Factor
    virtual bool IsSitting() const = 0;                               //Returns true if it is Seat 0 if Berth
    virtual bool IsAC() const = 0;                                    //Retuens 1 if AC 0 else
    virtual int GetNumberofTiers() const = 0;                         //Returns no. of tiers
    virtual bool IsLuxury() const = 0;                                //Returns 1 if Luxury 0 else
    virtual double GetTatkalLoadFactor() const = 0;                   //To get Tatkal load factor
    virtual double GetTatkalMinCharge() const = 0;                    //To get Tatkal load factor
    virtual double GetTatkalMaxCharge() const = 0;                    //To get Tatkal load factor
    virtual double GetTatkalMinDistance() const = 0;                  //To get Tatkal load factor
    virtual double GetReservationCharge() const = 0;                  //To get Reservation charge
    static bool UnitTestBookingClass();                               //For Unit Testing
    friend ostream &operator<<(ostream &os, const BookingClass &obj); //output stream operator
    typedef BookingClassNames<AC2Tier_> AC2Tier;
    typedef BookingClassNames<AC3Tier_> AC3Tier;
    typedef BookingClassNames<ACFirstClass_> ACFirstClass;
    typedef BookingClassNames<ACChairCar_> ACChairCar;
    typedef BookingClassNames<ExecutiveChairCar_> ExecutiveChairCar;
    typedef BookingClassNames<SecondSitting_> SecondSitting;
    typedef BookingClassNames<FirstClass_> FirstClass;
    typedef BookingClassNames<Sleeper_> Sleeper;
};
#endif