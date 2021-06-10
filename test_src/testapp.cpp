/**
 * @file testapp.cpp
 * @author Anurat Bhattacharya (19CS10071)
 * @brief TestApplication Implementation
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include "../test_include/testapp.h"

TestTotalApplication::TestTotalApplication()
{
    /**Running Application Tests**/

    //Initialize Passengers
    Passenger *P1 = NULL;
    Passenger *P2 = NULL;
    Passenger *P3 = NULL;
    Passenger *P4 = NULL;
    Passenger *P5 = NULL;
    Passenger *P6 = NULL;
    Passenger *P7 = NULL;
    Passenger *P8 = NULL;
    Passenger *P9 = NULL;
    stringstream ss;
    try
    {
        P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        P2 = Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda");
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        P4 = Passenger::CreatePassenger("844451263212", "11/11/2001", Gender::Male::Type(), "7455126438", "Luke", "", "Skywalker");
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        P6 = Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        P7 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        //BAD Aadhar
        P9 = Passenger::CreatePassenger("84125031012", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        //BAD phone
        P9 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "748512654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    try
    {
        //BAD name
        P9 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485126547", "", "", "", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }

    cout << "RUNNING  APPLICATION TEST...\n\n";

    bool flag = 1;
    /****************DO the bookings*****************/
    
    try
    {
        //Invalid date Format
        Booking *B1 = BookingCategory::General::Type().createBooking("Kolkata", "Mumbai", "1/4/2021", "7/4///85", BookingClass::AC2Tier::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //General
        Booking *B1 = BookingCategory::General::Type().createBooking("Kolkata", "Mumbai", "1/4/2021", "7/4/2021", BookingClass::AC2Tier::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Invalid Dates
        Booking *B2 = BookingCategory::General::Type().createBooking("Chennai", "Mumbai", "5/4/2021", "4/4/2021", BookingClass::SecondSitting::Type(), P3);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Invalid dates of reservation and booking
        Booking *B3 = BookingCategory::General::Type().createBooking("Delhi", "Kolkata", "4/4/2021", "5/6/2022", BookingClass::Sleeper::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Invalid station
        Booking *B4 = BookingCategory::General::Type().createBooking("Delhi", "Howrah", "4/4/2021", "5/6/2021", BookingClass::Sleeper::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }

    try
    {
        //Divyang
        Booking *B1 = BookingCategory::Divyang::Type().createBooking("Kolkata", "Mumbai", "1/4/2021", "7/4/2021", BookingClass::AC2Tier::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }

    try
    {
        //senior citizen
        Booking *B2 = BookingCategory::SeniorCitizen::Type().createBooking("Chennai", "Mumbai", "5/4/2021", "6/4/2021", BookingClass::SecondSitting::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }

    try
    {
        //Incompatible passenger and booking category
        Booking *B2 = BookingCategory::Divyang::Type().createBooking("Chennai", "Mumbai", "5/4/2021", "7/4/2021", BookingClass::SecondSitting::Type(), P5);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }

    try
    {
        //Invalid Dates
        Booking *B3 = BookingCategory::Ladies::Type().createBooking("Delhi", "Kolkata", "4/4/2021", "5/6/2022", BookingClass::Sleeper::Type(), P6);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Invalid station
        Booking *B4 = BookingCategory::SeniorCitizen::Type().createBooking("Delhi", "Amedabad", "4/4/2021", "5/6/2021", BookingClass::Sleeper::Type(), P5);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Tatkal by a Divyang Passenger
        Booking *B1 = BookingCategory::Tatkal::Type().createBooking("Kolkata", "Mumbai", "1/4/2021", "7/4/2021", BookingClass::AC2Tier::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Premium Tatkal
        Booking *B2 = BookingCategory::PremiumTatkal::Type().createBooking("Chennai", "Mumbai", "5/4/2021", "8/4/2021", BookingClass::SecondSitting::Type(), P3);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Invalid Date
        Booking *B2 = BookingCategory::PremiumTatkal::Type().createBooking("Chennai", "Mumbai", "5/4/2021", "4/4/2021", BookingClass::SecondSitting::Type(), P3);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Invalid Date
        Booking *B3 = BookingCategory::Tatkal::Type().createBooking("Delhi", "Kolkata", "4/4/2021", "5/6/2022", BookingClass::Sleeper::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        //Tatkal by Divyang Pass
        Booking *B3 = BookingCategory::Tatkal::Type().createBooking("Delhi", "Kolkata", "4/4/2021", "5/6/2021", BookingClass::Sleeper::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }

    for (Booking *itr : Booking::sBookings)
    {
        ss << *itr;
    }

    string op = ss.str();
    ss = stringstream();
    ifstream fin("../outputs/application_golden_output.txt");
    ss << fin.rdbuf();
    string golden = ss.str();
    if (op != golden)
    {
        cout << "Application Test Failed .Program Op not Matching with golden Op\n";
        cout << "EXPECTED OUTPUT:\n"
             << golden << endl;
        cout << "PROGRAM OUTPUT:\n"
             << op << endl;
        flag = 0;
    }
    else
    {
        cout << "PROGRAM OUTPUT:\n";
        cout << "-------------------\n";
        cout << op << endl;
        cout << "Application Test Passed\n";
        cout << "Program Output Matched with Golden Output\n";
    }
    cout << endl;
    //delete Passenegrs
    if (P1 != NULL)
        delete P1;
    if (P2 != NULL)
        delete P2;
    if (P3 != NULL)
        delete P3;
    if (P4 != NULL)
        delete P4;
    if (P5 != NULL)
        delete P5;
    if (P6 != NULL)
        delete P6;
    if (P7 != NULL)
        delete P7;
    if (P8 != NULL)
        delete P8;
    //Clear List of Bookings
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookingPNRSerial = 1;
    Booking::sBookings.clear();
}

int main()
{
    TestTotalApplication T;
    /**
    
    try
    {
        Booking *B1 = Booking::PriorityBooking::createBooking("Kolkata", "Mumbai", "1/4/2021", "7/4/2021", BookingClass::AC2Tier::Type(), BookingCategory::Tatkal::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B2 = Booking::PriorityBooking::createBooking("Chennai", "Mumbai", "5/4/2021", "8/4/2021", BookingClass::SecondSitting::Type(), BookingCategory::PremiumTatkal::Type(), P3);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B2 = Booking::PriorityBooking::createBooking("Chennai", "Mumbai", "5/4/2021", "4/4/2021", BookingClass::SecondSitting::Type(), BookingCategory::PremiumTatkal::Type(), P3);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B3 = Booking::PriorityBooking::createBooking("Delhi", "Kolkata", "4/4/2021", "5/6/2022", BookingClass::Sleeper::Type(), BookingCategory::Tatkal::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B3 = Booking::PriorityBooking::createBooking("Delhi", "Howrah", "4/4/2021", "5/6/2021", BookingClass::Sleeper::Type(), BookingCategory::Tatkal::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }*/
}