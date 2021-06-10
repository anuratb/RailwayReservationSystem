#include <iostream>
#include <cmath>
#include <string>
#include "booking.h"

#ifndef PRIORITY_BOOKING
#define PRIORITY_BOOKING
class PriorityBooking : public Booking
{
    PriorityBooking(const Station &frm, const Station &to, const Date& booking,const Date& reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger &P);

public:
    static PriorityBooking &createPriorityBooking(const string &frm, const string &to, const string & booking_dt, const string & reservation__dt, const BookingClass &tp, const BookingCategory &bookingCat, const Passenger &P);
    int ComputeFares() const; //To compute fare
    ~PriorityBooking();
};
#endif