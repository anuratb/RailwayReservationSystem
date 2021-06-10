#include "../include/bookingname.h"

template <typename T>
BookingNames<T>::BookingNames(const Station &frm, const Station &to, const Date &booking, const Date &reservation, const BookingClass &tp, const BookingCategory &bookingCat, const Passenger &P)
    : Booking(frm, to, booking, reservation, tp, bookingCat, P)
{
    Booking::sBookings.push_back(this);
}

template <typename T>
BookingNames<T> *BookingNames<T>::createBooking(const string &frm, const string &to, const string &booking_dt, const string &reservation__dt, const BookingClass &tp, const BookingCategory &bookingCat, const Passenger *P)
{
    try
    {
        if (P == NULL)
        {
            throw Bad_Booking("Null Passenger");
        }
        if (!(bookingCat.getEligibility(*P)))
        {
            throw Bad_Booking_passenger();
        }
        //TODO Passenger Booking Cat Validation
        Station *toSt = Station::createStation(to);
        Station *frmSt = Station::createStation(frm);
        //validate station
        bool flag = 1;
        for (Station *itr : Railways::sStations)
        {
            if (itr->GetName() == frmSt->GetName())
                flag = 0;
        }
        if (flag)
            throw Bad_Booking_st();
        flag = 1;
        for (Station *itr : Railways::sStations)
        {
            if (itr->GetName() == toSt->GetName())
                flag = 0;
        }
        if (flag)
            throw Bad_Booking_st();

        Date date_booking = Date::createDate(booking_dt);
        Date date_resv = Date::createDate(reservation__dt);
        if (diffDate(date_booking, date_resv) > 366 || diffDate(date_booking, date_resv) < 1)
        {
            throw Bad_Booking_date();
        }
        return new BookingNames<T>(*toSt, *frmSt, date_booking, date_resv, tp, bookingCat, *P);
    }
    catch (const exception &e)
    {
        throw;
    }
}

template <>
int Booking::GeneralBooking::ComputeFares() const
{
    double fare = fromStation_.GetDistance(toStation_) * Booking::sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();
    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template <>
int Booking::PriorityBooking::ComputeFares() const
{
    double fare = fromStation_.GetDistance(toStation_) * Booking::sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();
    double tatkal_charge = bookingClass_.GetTatkalLoadFactor() * fare;
    //cout<<"0::"<<tatkal_charge<<endl;
    if (tatkal_charge > bookingClass_.GetTatkalMaxCharge())
        tatkal_charge = bookingClass_.GetTatkalMaxCharge();
    //cout<<"1::"<<tatkal_charge<<endl;
    if (tatkal_charge < bookingClass_.GetTatkalMinCharge())
        tatkal_charge = bookingClass_.GetTatkalMinCharge();
    //cout<<"2::"<<tatkal_charge<<endl;
    if (fromStation_.GetDistance(toStation_) < bookingClass_.GetTatkalMinDistance())
        tatkal_charge = 0.0;
    //cout<<"3::"<<tatkal_charge<<endl;
    tatkal_charge *= bookingCat_.getpFactor();
    //cout<<"4::"<<tatkal_charge<<endl;
    fare += tatkal_charge;
    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template <>
int Booking::ConcessionalBooking::ComputeFares() const
{
    double fare = fromStation_.GetDistance(toStation_) * Booking::sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();
    fare *= (1 - bookingCat_.getConcession(p_, bookingClass_));
    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template <>
Booking *BookingCategory::General::createBooking(const string &frm,
                                                 const string &to,
                                                 const string &date_booking,
                                                 const string &date_reservation,
                                                 const BookingClass &tp,
                                                 const Passenger *P) const
{
    return Booking::GeneralBooking::createBooking(frm, to, date_booking, date_reservation, tp, BookingCategory::General::Type(), P);
}
template <>
Booking *BookingCategory::Divyang::createBooking(const string &frm,
                                                 const string &to,
                                                 const string &date_booking,
                                                 const string &date_reservation,
                                                 const BookingClass &tp,
                                                 const Passenger *P) const
{
    return Booking::ConcessionalBooking::createBooking(frm, to, date_booking, date_reservation, tp, BookingCategory::Divyang::Type(), P);
}
template <>
Booking *BookingCategory::SeniorCitizen::createBooking(const string &frm,
                                                       const string &to,
                                                       const string &date_booking,
                                                       const string &date_reservation,
                                                       const BookingClass &tp,
                                                       const Passenger *P) const
{
    return Booking::ConcessionalBooking::createBooking(frm, to, date_booking, date_reservation, tp, BookingCategory::SeniorCitizen::Type(), P);
}
template <>
Booking *BookingCategory::Ladies::createBooking(const string &frm,
                                                const string &to,
                                                const string &date_booking,
                                                const string &date_reservation,
                                                const BookingClass &tp,
                                                const Passenger *P) const
{
    return Booking::ConcessionalBooking::createBooking(frm, to, date_booking, date_reservation, tp, BookingCategory::Ladies::Type(), P);
}
template <>
Booking *BookingCategory::Tatkal::createBooking(const string &frm,
                                                const string &to,
                                                const string &date_booking,
                                                const string &date_reservation,
                                                const BookingClass &tp,
                                                const Passenger *P) const
{
    return Booking::PriorityBooking::createBooking(frm, to, date_booking, date_reservation, tp, BookingCategory::Tatkal::Type(), P);
}
template <>
Booking *BookingCategory::PremiumTatkal::createBooking(const string &frm,
                                                       const string &to,
                                                       const string &date_booking,
                                                       const string &date_reservation,
                                                       const BookingClass &tp,
                                                       const Passenger *P) const
{
    return Booking::PriorityBooking::createBooking(frm, to, date_booking, date_reservation, tp, BookingCategory::PremiumTatkal::Type(), P);
}

template <>
bool Booking::GeneralBooking::UnitTestBookingName()
{
    //Booking b
    //CLear Prev bookings
    cout<<"Doing Unit Tests for General Booking"<<endl;
    bool flag = 1;
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookingPNRSerial=1;
    Booking::sBookings.clear();
    //Create Passengers
    Passenger *P1=NULL;
    Passenger *P2=NULL;
    Passenger *P3=NULL;
    Passenger *P4=NULL;
    Passenger *P5=NULL;
    Passenger *P6=NULL;
    Passenger *P7=NULL;
    Passenger *P8=NULL;
    try
    {
        P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());
        P2 = Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda");
        P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
        P4 = Passenger::CreatePassenger("844451263212", "11/11/2001", Gender::Male::Type(), "7455126438", "Luke", "", "Skywalker");
        P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
        P6 = Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
        P7 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
        P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        cout << e.what() << '\n';
    }
    stringstream ss;
    try
    {
        Booking *B1 = Booking::GeneralBooking::createBooking("Kolkata", "Mumbai", "1/4/2021", "7/4/2021", BookingClass::AC2Tier::Type(), BookingCategory::General::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B2 = Booking::GeneralBooking::createBooking("Chennai", "Mumbai", "5/4/2021", "4/4/2021", BookingClass::SecondSitting::Type(), BookingCategory::General::Type(), P3);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B3 = Booking::GeneralBooking::createBooking("Delhi", "Kolkata", "4/4/2021", "5/6/2022", BookingClass::Sleeper::Type(), BookingCategory::General::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B3 = Booking::GeneralBooking::createBooking("Delhi", "Howrah", "4/4/2021", "5/6/2021", BookingClass::Sleeper::Type(), BookingCategory::General::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    for(Booking* itr:Booking::sBookings)
    {        
        ss<<*itr;
    }
    string op = ss.str();
    ss = stringstream();
    ifstream fin("../outputs/unit_test_goldens/generalbooking.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    if(op!=golden)
    {
        cout<<"Error in General Booking\n";
        cout<<"EXPECTED OUTPUT:\n"<<golden<<endl;
        cout<<"PROGRAM OUTPUT:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors in General Booking\n";
    }
    cout<<endl;
    //delete Passenegrs
    if(P1!=NULL)    delete P1;
    if(P2!=NULL)    delete P2;
    if(P3!=NULL)    delete P3;
    if(P4!=NULL)    delete P4;
    if(P5!=NULL)    delete P5;
    if(P6!=NULL)    delete P6;
    if(P7!=NULL)    delete P7;
    if(P8!=NULL)    delete P8;
    //Clear List of Bookings
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookingPNRSerial=1;
    Booking::sBookings.clear();
    return flag;

}
template <>
bool Booking::ConcessionalBooking::UnitTestBookingName()
{
    //Booking b
    //CLear Prev bookings
    cout<<"Doing Unit Tests for Concessional Booking"<<endl;
    bool flag = 1;
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookingPNRSerial=1;
    Booking::sBookings.clear();
    Passenger *P1=NULL;
    Passenger *P2=NULL;
    Passenger *P3=NULL;
    Passenger *P4=NULL;
    Passenger *P5=NULL;
    Passenger *P6=NULL;
    Passenger *P7=NULL;
    Passenger *P8=NULL;
    try
    {
        P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());
        P2 = Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda");
        P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
        P4 = Passenger::CreatePassenger("844451263212", "11/11/2001", Gender::Male::Type(), "7455126438", "Luke", "", "Skywalker");
        P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
        P6 = Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
        P7 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
        P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        cout << e.what() << '\n';
    }
    stringstream ss;
    try
    {
        Booking *B1 = Booking::ConcessionalBooking::createBooking("Kolkata", "Mumbai", "1/4/2021", "7/4/2021", BookingClass::AC2Tier::Type(), BookingCategory::Divyang::Type(), P1);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B2 = Booking::ConcessionalBooking::createBooking("Chennai", "Mumbai", "5/4/2021", "6/4/2021", BookingClass::SecondSitting::Type(), BookingCategory::SeniorCitizen::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B2 = Booking::ConcessionalBooking::createBooking("Chennai", "Mumbai", "5/4/2021", "4/4/2021", BookingClass::SecondSitting::Type(), BookingCategory::SeniorCitizen::Type(), P2);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B3 = Booking::ConcessionalBooking::createBooking("Delhi", "Kolkata", "4/4/2021", "5/6/2022", BookingClass::Sleeper::Type(), BookingCategory::SeniorCitizen::Type(), P5);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Booking *B4 = Booking::ConcessionalBooking::createBooking("Delhi", "Amedabad", "4/4/2021", "5/6/2021", BookingClass::Sleeper::Type(), BookingCategory::SeniorCitizen::Type(), P5);
    }
    catch (const std::exception &e)
    {
        ss << e.what() << '\n';
    }
    for(Booking* itr:Booking::sBookings)
    {        
        ss<<*itr;
    }
    string op = ss.str();
    ss = stringstream();
    ifstream fin("../outputs/unit_test_goldens/concessionalbooking.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    if(op!=golden)
    {
        cout<<"Error in Concessional Booking\n";
        cout<<"EXPECTED OUTPUT:\n"<<golden<<endl;
        cout<<"PROGRAM OUTPUT:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors in Concessional Booking\n";
    }
    cout<<endl;
    if(P1!=NULL)    delete P1;
    if(P2!=NULL)    delete P2;
    if(P3!=NULL)    delete P3;
    if(P4!=NULL)    delete P4;
    if(P5!=NULL)    delete P5;
    if(P6!=NULL)    delete P6;
    if(P7!=NULL)    delete P7;
    if(P8!=NULL)    delete P8;
    //Clear List of Bookings
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    
    Booking::sBookings.clear();
    Booking::sBookingPNRSerial=1;
    return flag;
}
template <>
bool Booking::PriorityBooking::UnitTestBookingName()
{
    //Booking b
    //CLear Prev bookings
    cout<<"Doing Unit Tests for Priority Booking"<<endl;
    bool flag = 1;
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookingPNRSerial=1;
    Booking::sBookings.clear();
    //Create Passengers
    Passenger *P1=NULL;
    Passenger *P2=NULL;
    Passenger *P3=NULL;
    Passenger *P4=NULL;
    Passenger *P5=NULL;
    Passenger *P6=NULL;
    Passenger *P7=NULL;
    Passenger *P8=NULL;
    try
    {
        P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());
        P2 = Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda");
        P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
        P4 = Passenger::CreatePassenger("844451263212", "11/11/2001", Gender::Male::Type(), "7455126438", "Luke", "", "Skywalker");
        P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
        P6 = Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
        P7 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
        P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        cout << e.what() << '\n';
    }
    stringstream ss;
    //DO the bookings
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
    }
    for(Booking* itr:Booking::sBookings)
    {        
        ss<<*itr;
    }
    string op = ss.str();
    ss = stringstream();
    ifstream fin("../outputs/unit_test_goldens/prioritybooking.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    if(op!=golden)
    {
        cout<<"Error in Priority Booking\n";
        cout<<"EXPECTED OUTPUT:\n"<<golden<<endl;
        cout<<"PROGRAM OUTPUT:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors in Priority Booking\n";
    }
    cout<<endl;
    //delete Passenegrs
    if(P1!=NULL)    delete P1;
    if(P2!=NULL)    delete P2;
    if(P3!=NULL)    delete P3;
    if(P4!=NULL)    delete P4;
    if(P5!=NULL)    delete P5;
    if(P6!=NULL)    delete P6;
    if(P7!=NULL)    delete P7;
    if(P8!=NULL)    delete P8;
    //Clear List of Bookings
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookings.clear();
    Booking::sBookingPNRSerial=1;
    return flag;
}

bool Booking::UnitTestBooking()
{
    //Booking b
    //CLear Prev bookings
    cout<<"Doing Unit Tests for Booking Base Class"<<endl;
    bool flag = 1;
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookingPNRSerial=1;
    Booking::sBookings.clear();
    //Create Passengers
    Passenger *P1=NULL;
    Passenger *P2=NULL;
    Passenger *P3=NULL;
    Passenger *P4=NULL;
    Passenger *P5=NULL;
    Passenger *P6=NULL;
    Passenger *P7=NULL;
    Passenger *P8=NULL;
    try
    {
        P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());
        P2 = Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda");
        P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
        P4 = Passenger::CreatePassenger("844451263212", "11/11/2001", Gender::Male::Type(), "7455126438", "Luke", "", "Skywalker");
        P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
        P6 = Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
        P7 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
        P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        cout << e.what() << '\n';
    }
    stringstream ss;
    //DO the bookings
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
    }
    for(Booking* itr:Booking::sBookings)
    {        
        ss<<*itr;
    }
    string op = ss.str();
    ss = stringstream();
    ifstream fin("../outputs/unit_test_goldens/prioritybooking.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    if(op!=golden)
    {
        cout<<"Error in Booking Base Class\n";
        cout<<"EXPECTED OUTPUT:\n"<<golden<<endl;
        cout<<"PROGRAM OUTPUT:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors in Booking\n";
    }
    cout<<endl;
    //delete Passenegrs
    if(P1!=NULL)    delete P1;
    if(P2!=NULL)    delete P2;
    if(P3!=NULL)    delete P3;
    if(P4!=NULL)    delete P4;
    if(P5!=NULL)    delete P5;
    if(P6!=NULL)    delete P6;
    if(P7!=NULL)    delete P7;
    if(P8!=NULL)    delete P8;
    //Clear List of Bookings
    for (Booking *itr : Booking::sBookings)
    {
        delete itr;
    }
    Booking::sBookings.clear();
    Booking::sBookingPNRSerial=1;
    return flag;
}
template <typename T>
BookingNames<T>::~BookingNames() {}