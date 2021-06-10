#include <iostream>
#include <cmath>
#include <string>
#include "booking.h"

#ifndef BOOKING_NAME
#define BOOKING_NAME

template<typename T>
class BookingNames : public Booking
{
    BookingNames (const Station &frm, const Station &to, const Date& booking,const Date& reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger &P);

public:    
    static BookingNames *createBooking(const string &frm, const string &to, const string& date_booking,const string & date_reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger *P);
    int ComputeFares() const; //To compute fare
    static bool UnitTestBookingName();
    ~BookingNames();        //Destructor
};
#endif