/**
 * @file testapp.cpp
 * @author Anurat Bhattacharya (19CS10071)
 * @brief TestApplication Implementation
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include "../test_include/testunit.h"

TestApplication::TestApplication() : unitTests_(35), unitTestsPassed_(0), tests_(7), testsPassed_(0)
{
    /**Running All unit Tests**/
    Passenger *P1=NULL;
    Passenger *P2=NULL;
    Passenger *P3=NULL;
    Passenger *P4=NULL;
    Passenger *P5=NULL;
    Passenger *P6=NULL;
    Passenger *P7=NULL;
    Passenger *P8=NULL;

    
    cout << "RUNNING " << unitTests_ << " UNIT TESTS...\n\n";
    if (Date::UnitTestDate())
        unitTestsPassed_++;
    if (Station::UnitTestStation())
        unitTestsPassed_++;
    if (Railways::UnitTestRailways())
        unitTestsPassed_++; 
    if( Gender::UnitTestGender())
        unitTestsPassed_++;
    if( Gender::Female::UnitTestGenderType())
        unitTestsPassed_++;
    if( Gender::Male::UnitTestGenderType())
        unitTestsPassed_++;
    if (Passenger::UnitTestPassenger())
    {
            P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());
            P2 = Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda");
            P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
            P4 = Passenger::CreatePassenger("844451263212", "11/11/2001", Gender::Male::Type(), "7455126438", "Luke", "", "Skywalker");
            P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
            P6 = Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
            P7 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
            P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
            
        unitTestsPassed_++;
    }
    //Testing Booking category
    if(BookingCategory::General::UnitTestCategoryNames(P3,P1))
        unitTestsPassed_++;
    if(BookingCategory::Ladies::UnitTestCategoryNames(P6,P1))
        unitTestsPassed_++;
    if(BookingCategory::SeniorCitizen::UnitTestCategoryNames(P2,P1))
        unitTestsPassed_++;
    if(BookingCategory::Divyang::UnitTestCategoryNames(P1,P2))
        unitTestsPassed_++;
    if(BookingCategory::UnitTestBookingCategory(P2))
        unitTestsPassed_++;
    //Testing Booking Class
    if (BookingClass::UnitTestBookingClass())
        unitTestsPassed_++;
    if (BookingClass::AC2Tier::UnitTestBookingClassNames())
        unitTestsPassed_++;
    if (BookingClass::AC3Tier::UnitTestBookingClassNames())
        unitTestsPassed_++;
    if (BookingClass::ACFirstClass::UnitTestBookingClassNames())
        unitTestsPassed_++;
    if (BookingClass::ExecutiveChairCar::UnitTestBookingClassNames())
        unitTestsPassed_++;
    if (BookingClass::ACChairCar::UnitTestBookingClassNames())
        unitTestsPassed_++;
    if (BookingClass::FirstClass::UnitTestBookingClassNames())
        unitTestsPassed_++;
    if (BookingClass::Sleeper::UnitTestBookingClassNames())
        unitTestsPassed_++;
    if (BookingClass::SecondSitting::UnitTestBookingClassNames())
        unitTestsPassed_++;
    //Testing Divyang Class
    if(Divyang::Blind::UnitTestingDivyangNames())
        unitTestsPassed_++;
    if(Divyang::Ortho::UnitTestingDivyangNames())
        unitTestsPassed_++;
    if(Divyang::Cancer::UnitTestingDivyangNames())
        unitTestsPassed_++;
    if(Divyang::Tb::UnitTestingDivyangNames())
        unitTestsPassed_++;
    if(Divyang::UnitTestDivyang())
        unitTestsPassed_++;
    //Testing Concessions Class
    if(Concessions::UnitTestConcession())
        unitTestsPassed_++;
    if(GeneralConcession::UnitTestGeneralConcession())
        unitTestsPassed_++;
    if(LadiesConcession::UnitTestLadiesConcession())
        unitTestsPassed_++;
    if(DivyangConcession::UnitTestDivyangConcession())
        unitTestsPassed_++;
    if(SrCitizenConcession::UnitTestSrCitizenConcession())
        unitTestsPassed_++;
        //Testing Booking
    if(Booking::GeneralBooking::UnitTestBookingName())
        unitTestsPassed_++;
    if(Booking::ConcessionalBooking::UnitTestBookingName())
        unitTestsPassed_++;
    if(Booking::PriorityBooking::UnitTestBookingName())
        unitTestsPassed_++;
    if(Booking::UnitTestBooking())
        unitTestsPassed_++;
    

        /*
    if (BookingClass::UnitTestBookingClass())
        unitTestsPassed_++;
    if (Booking::UnitTestBooking())
        unitTestsPassed_++;
        */
    

    cout << endl
         << "Passed " << unitTestsPassed_ << " out of " << unitTests_ << " tests\n";
    /**
    //Running Application tests
    cout<<endl;
    string op;
    stringstream ss;    
    cout<<"RUNNING APPLICATION\n";    
    Booking b1(Station("Kolkata"), Station("Chennai"), Date(2, 3, 2019), ACFirstClass::Type());
    Booking b2(Station("Delhi"), Station("Banglore"), Date(3, 3, 2019), AC2Tier::Type());
    Booking b3(Station("Chennai"), Station("Mumbai"), Date(3, 3, 2019), AC3Tier::Type());
    Booking b4(Station("Mumbai"), Station("Banglore"), Date(4, 3, 2019), ACChairCar::Type());
    Booking b5(Station("Banglore"), Station("Kolkata"), Date(5, 3, 2019), FirstClass::Type());
    Booking b6(Station("Kolkata"), Station("Mumbai"), Date(6, 3, 2019), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Chennai"), Date(6, 3, 2019), SecondSitting::Type());
    vector<Booking *>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
    {
        ss << *(*it);        
    }
    op = ss.str();    
    cout<<op;
    ifstream fin;
    fin.open("../outputs/application_golden_output.txt",ios::in);    
    string line;
    string golden_op;
    stringstream g_op;
    g_op<<fin.rdbuf();
    golden_op = g_op.str();        
    if(golden_op==op)
    {
        cout<<"Application Test Passed.Output matched with golden output\n";
    }
    else
    {
        cout<<"Expected Output:\n";
        cout<<golden_op;
        cout<<"Application Test Failed .Output not Matching with golden output.\n";
    }
    
    fin.close();
    */
    
}

int main()
{
    TestApplication T;
}