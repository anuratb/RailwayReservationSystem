/**
 * @file booking.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief Booking  HEader
 * @version 0.1
 * @date 2021-03-06
 * 
 */

#include <iostream>
#include <cmath>
#include<algorithm>
#include <string>
#include "railways.h"
#include "date.h"
#include "passenger.h"
#include "bookingclass.h"
#include "bookingClassNames.h"
#include "BookingCategory.h"
#include "BookingCategoryNames.h"
#include "bad_booking.h"
using namespace std;
#ifndef BOOKING_INC
#define BOOKING_INC

template<typename T> 
class BookingNames;

class Booking
{
    struct GeneralBooking_{};
    struct ConcessionalBooking_{};
    struct PriorityBooking_{};
    /*****BLocked CCR and CAO*****/
    Booking(const Booking &other);            //CCR
    Booking &operator=(const Booking &other); //CAO
protected:
    Station fromStation_;                                                                               //From Station
    Station toStation_;                                                                                 //To Station
    Date dateofBooking_;                                                                                //Date of Booking
    Date dateofReservation_;                                                                            //Date of Reservation
    const BookingClass &bookingClass_;                                                                  //Booking Class
    const BookingCategory &bookingCat_;                                                                 //Booking Category
    const Passenger p_;                                                                                 //Passenger
    int pnr_;                                                                                           //PNR number
    Booking(const Station &frm, const Station &to, const Date& booking,const Date& reservation, const BookingClass &tp,const BookingCategory &bookingCat ,const Passenger &P); //CR
    

public:
    /****Static Constants******/
    static const double sBaseFarePerKM;    //Base Fare Per Km
    static vector<Booking *> sBookings;    //List of all bookings done
    static int sBookingPNRSerial;          //next available PNR
    

    /****** public methods*******/

    friend ostream &operator<<(ostream &os, const Booking &booking); ///Output stream operator
    virtual int ComputeFares() const = 0;                            //To compute Fares
    static bool UnitTestBooking();                                  //Unit Testing

    /********TypeDefs***********/
    typedef BookingNames<GeneralBooking_> GeneralBooking;
    typedef BookingNames<ConcessionalBooking_> ConcessionalBooking;
    typedef BookingNames<PriorityBooking_> PriorityBooking;

    virtual ~Booking();

    


};
#endif