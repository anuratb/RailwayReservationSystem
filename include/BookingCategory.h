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
#include "passenger.h"
#include "bookingclass.h"
#include "bookingClassNames.h"
#include "concessions.h"
#include "genConcessions.h"
#include "ladiesConcessions.h"
#include "srcitizenConcessions.h"
#include "divyangConcessions.h"
#include "gender.h"
#include "genderTypes.h"
using namespace std;

#ifndef BOOKINGCATEGORY_INC
#define BOOKINGCATEGORY_INC

template <typename T>
class BookingCategoryNames;

class Booking;

class BookingCategory
{
    const string categoryName_;
    struct General_
    {
    };
    struct SrCitizen_
    {
    };
    struct Divyang_
    {
    };
    struct Tatkal_
    {
    };
    struct PremiumTatkal_
    {
    };
    struct Ladies_
    {
    };

protected:
    BookingCategory(string nme);
    virtual ~BookingCategory();

public:
    virtual Booking* createBooking(const string &frm,
                                   const string &to,
                                   const string &date_booking,
                                   const string &date_reservation,
                                   const BookingClass &tp,
                                   const Passenger *P) const = 0;
    virtual bool getEligibility(const Passenger &P) const = 0;
    inline string getCategoryName() const { return categoryName_; }
    virtual double getConcession(const Passenger &P, const BookingClass &B) const = 0;
    virtual double getpFactor() const = 0;
    friend ostream& operator<<(ostream& os,const BookingCategory& bookCat);
    static bool UnitTestBookingCategory(Passenger *P);
    typedef BookingCategoryNames<General_> General;
    typedef BookingCategoryNames<SrCitizen_> SeniorCitizen;
    typedef BookingCategoryNames<Divyang_> Divyang;
    typedef BookingCategoryNames<Ladies_> Ladies;
    typedef BookingCategoryNames<Tatkal_> Tatkal;
    typedef BookingCategoryNames<PremiumTatkal_> PremiumTatkal;
};

#endif