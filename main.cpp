/**
 * @file main.cpp
 * @author Anurat Bhattacharya (19CS10071)
 * @brief Sample AppTest 
 * @version 0.1
 * @date 2021-03-06
 *  
 */
#include "include/booking.h"
#include "include/bookingname.h"
#include "include/gender.h"

#include "include/genderTypes.h"

// Test application for booking

void BookingApplication()
{
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Passenger *P1;
    Passenger *P2;
    Passenger *P3;
    Passenger *P4;
    Passenger *P5;
    Passenger *P6;
    Passenger *P7;
    Passenger *P8;

    P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());
    P2 = Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda");
    P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
    P4 = Passenger::CreatePassenger("844451263212", "11/11/2001", Gender::Male::Type(), "7455126438", "Luke", "", "Skywalker");
    P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
    P6 = Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
    P7 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
    P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    if(P1) cout << *P1 << endl;
    if(P2)  cout << *P2 << endl;
    if(P3)  cout << *P3 << endl;
    if(P4)  cout << *P4 << endl;
    if(P5)  cout << *P5 << endl;
    if(P6)  cout << *P6 << endl;
    if(P7)  cout << *P7 << endl;
    if(P8)  cout << *P8 << endl;

    BookingCategory::Tatkal::Type().createBooking("Mumbai", "Delhi", "15/2/2021", "16/2/2021", BookingClass::AC3Tier::Type(), P1);

    /*
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());
    */
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking *>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
    {
        cout << *(*it);
    }
    return;
}

int main()
{
    BookingApplication();
    return 0;
}