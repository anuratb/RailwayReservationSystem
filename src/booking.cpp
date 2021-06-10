/**
 * @file booking.cpp
 * @author Anurat Bhattacharya
 * @brief Booking Implementation
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include "../include/booking.h"

vector<Booking *> Booking::sBookings = vector<Booking *>();
int Booking::sBookingPNRSerial = 1;
const double Booking::sBaseFarePerKM = 0.50;
//CR
Booking::Booking(const Station &frm, const Station &to, const Date& booking,const Date& reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger &P) 
: fromStation_(frm), toStation_(to), dateofBooking_(booking),
dateofReservation_(reservation), bookingClass_(tp) ,bookingCat_(bookingCat),p_(P),
pnr_(Booking::sBookingPNRSerial)
{
    Booking::sBookingPNRSerial++;
    //Booking::sBookings.push_back(this);//To be done in derived classes
}
//CCR
Booking::Booking(const Booking &other) : fromStation_(other.fromStation_), 
toStation_(other.toStation_), dateofBooking_(other.dateofBooking_),
dateofReservation_(other.dateofReservation_), bookingClass_(other.bookingClass_),bookingCat_(other.bookingCat_), 
p_(other.p_) ,pnr_(Booking::sBookingPNRSerial)
{
    Booking::sBookingPNRSerial++;
    //Booking::sBookings.push_back(this);
}
//CAO
Booking &Booking::operator=(const Booking &other) //Blocked
{
    return *this;
}
ostream &operator<<(ostream &os, const Booking &booking) //Output stream operator
{

    os << "BOOKING SUCCEEDED:\n";
    os << "PNR Number = " << booking.pnr_ << endl;
    os << "From Station = " << booking.fromStation_ << endl;
    os << "To Station = " << booking.toStation_ << endl;
    os << "Booking Date = " << booking.dateofBooking_ << endl;
    os << "Travel Date = " << booking.dateofReservation_ << endl;
    os << "Travel Class = " << booking.bookingClass_;
    os << "Booking Category = " << booking.bookingCat_<<endl;
    os << "Fare = " << booking.ComputeFares() << endl;
    os << booking.p_<<endl;
    os << endl;
    return os;
}

Booking::~Booking()
{
    
} //Destructor
