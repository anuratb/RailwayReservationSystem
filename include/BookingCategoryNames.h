#include <iostream>
#include <string>
#include "BookingCategory.h"

using namespace std;

#ifndef CATEGORYNAMES_INC
#define CATEGORYNAMES_INC

template <typename T>
class BookingCategoryNames : public BookingCategory
{

    BookingCategoryNames(const string &nme = BookingCategoryNames<T>::sCategoryName) : BookingCategory(nme) {} //CR
    virtual ~BookingCategoryNames(){};                                                                         //Destructor
public:
    Booking *createBooking(const string &frm,
                                   const string &to,
                                   const string &date_booking,
                                   const string &date_reservation,
                                   const BookingClass &tp,
                                   const Passenger *P) const ;
    double getConcession(const Passenger &P, const BookingClass &B) const ;
    inline double getpFactor() const {return spFactor;}
    static const double spFactor ;//2 for premium tatkal,1 for tatkal 0 for else
    bool getEligibility(const Passenger &) const; //TODO
    static const string sCategoryName;
    static bool UnitTestCategoryNames(Passenger *P,Passenger *P1);//For unit testing
    static const BookingCategoryNames<T> &Type() //To return Singleton object
    {
        static const BookingCategoryNames<T> Obj;
        return Obj;
    }
};

#endif