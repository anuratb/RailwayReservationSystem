#include <iostream>
#include <cmath>
#include <string>
#include "booking.h"

#ifndef CONCESSIONAL_BOOKING
#define CONCESSIONAL_BOOKING
class ConcessionalBooking : public Booking
{
    ConcessionalBooking(const Station &frm, const Station &to, const Date &booking, const Date &reservation, const BookingClass &tp, const BookingCategory &bookingCat, const Passenger &P) ;

public:
    static ConcessionalBooking &createConcessionalBooking(const string &frm, const string &to, const string& date_booking,const string & date_reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger &P);
    int ComputeFares() const;
    ~ConcessionalBooking();
};
#endif