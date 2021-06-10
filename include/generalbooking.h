#include <iostream>
#include <cmath>
#include <string>
#include "booking.h"

#ifndef GEN_BOOKING
#define GEN_BOOKING
class GeneralBooking : public Booking
{
    GeneralBooking(const Station &frm, const Station &to, const Date& booking,const Date& reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger &P);

public:
    static GeneralBooking &createGeneralBooking(const string &frm, const string &to, const string& date_booking,const string & date_reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger &P);
    int ComputeFares() const; //To compute fare
    ~GeneralBooking();        //Destructor
};
#endif