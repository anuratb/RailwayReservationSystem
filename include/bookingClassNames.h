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
#include "bookingclass.h"
using namespace std;
#ifndef BOOKINGCLASSNAMES_INC
#define BOOKINGCLASSNAMES_INC

template <typename T>
class BookingClassNames : public BookingClass
{
    BookingClassNames(const string& nme = BookingClassNames<T>::sBookingClassName,int id = BookingClassNames<T>::sBookingClassId) :BookingClass(nme,id) {}//CR
    //TODO block CAO and CCR
    virtual ~BookingClassNames() {};//Destructor
    static const string sBookingClassName;
    static const bool sIsAC;
    static bool sIsLuxury;
    static const int sTiers;
    static const bool sIsSitting;
    static double sLoadFactor;
    static double sTatkalLoadFactor;
    static double sMinTatkalCharge;
    static double sMaxTatkalCharge;
    static double sMinTatkalDistance;
    static double sReservationCharge;
    static const int sBookingClassId;  //Unique id for diff booking classess {0,1,...}
    
public:
    inline int GetClassId() const {return sBookingClassId;}
    inline string GetName() const { return sBookingClassName; }                                //To get name
    inline double GetLoadFactor() const {return sLoadFactor;}                                      //To Get Load Factor
    inline bool IsSitting() const {return sIsSitting;}                                            //Returns true if it is Seat 0 if Berth
    inline bool IsAC() const {return sIsAC;}                                                 //Retuens 1 if AC 0 else
    inline int GetNumberofTiers() const {return sTiers;}                                      //Returns no. of tiers
    inline bool IsLuxury() const {return sIsLuxury;}                                             //Returns 1 if Luxury 0 else
    inline double GetTatkalLoadFactor() const {return sTatkalLoadFactor;}                                //To get Tatkal load factor
    inline double GetTatkalMinCharge() const {return sMinTatkalCharge;}                                 //To get Tatkal load factor
    inline double GetTatkalMaxCharge() const {return sMaxTatkalCharge;}                                 //To get Tatkal load factor
    inline double GetTatkalMinDistance() const {return sMinTatkalDistance;}                               //To get Tatkal load factor
    inline double GetReservationCharge() const {return sReservationCharge;}//To get Reservation charge
    static bool UnitTestBookingClassNames();                               //For Unit Testing
    static const BookingClassNames<T>& Type()//To return Singleton object
    {
        static const BookingClassNames<T> Obj;
        return Obj;
    }
};

#endif