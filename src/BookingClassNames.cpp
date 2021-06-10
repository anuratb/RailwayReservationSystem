#include "../include/bookingClassNames.h"
//Name Init
template<> const string BookingClass::AC2Tier::sBookingClassName = "AC 2 Tier";
template<> const string BookingClass::AC3Tier::sBookingClassName = "AC 3 Tier";
template<> const string BookingClass::ACChairCar::sBookingClassName = "AC Chair Car";
template<> const string BookingClass::ACFirstClass::sBookingClassName = "AC First Class";
template<> const string BookingClass::ExecutiveChairCar::sBookingClassName = "Executive Chair Car";
template<> const string BookingClass::Sleeper::sBookingClassName = "Sleeper";
template<> const string BookingClass::FirstClass::sBookingClassName = "First Class";
template<> const string BookingClass::SecondSitting::sBookingClassName = "Second Sitting";
//IsAC init
template<> const bool BookingClass::AC2Tier::sIsAC =  1;
template<> const bool BookingClass::AC3Tier::sIsAC =  1;
template<> const bool BookingClass::ACChairCar::sIsAC =  1;
template<> const bool BookingClass::ACFirstClass::sIsAC =  1;
template<> const bool BookingClass::ExecutiveChairCar::sIsAC = 1; 
template<> const bool BookingClass::Sleeper::sIsAC =  0;
template<> const bool BookingClass::FirstClass::sIsAC =  0;
template<> const bool BookingClass::SecondSitting::sIsAC =  0;
//ISSitting Init
template<> const bool BookingClass::AC2Tier::sIsSitting =  0;
template<> const bool BookingClass::AC3Tier::sIsSitting =  0;
template<> const bool BookingClass::ACChairCar::sIsSitting =  1;
template<> const bool BookingClass::ACFirstClass::sIsSitting =  0;
template<> const bool BookingClass::ExecutiveChairCar::sIsSitting = 1; 
template<> const bool BookingClass::Sleeper::sIsSitting =  0;
template<> const bool BookingClass::FirstClass::sIsSitting =  0;
template<> const bool BookingClass::SecondSitting::sIsSitting =  1;
//ISLuxury Init
template<> bool BookingClass::AC2Tier::sIsLuxury =  0;
template<> bool BookingClass::AC3Tier::sIsLuxury =  0;
template<> bool BookingClass::ACChairCar::sIsLuxury =  0;
template<> bool BookingClass::ACFirstClass::sIsLuxury =  1;
template<> bool BookingClass::ExecutiveChairCar::sIsLuxury = 1; 
template<> bool BookingClass::Sleeper::sIsLuxury =  0;
template<> bool BookingClass::FirstClass::sIsLuxury =  1;
template<> bool BookingClass::SecondSitting::sIsLuxury =  0;
//ID
template<> const int BookingClass::AC2Tier::sBookingClassId =  0;
template<> const int BookingClass::AC3Tier::sBookingClassId =  1;
template<> const int BookingClass::ACChairCar::sBookingClassId = 2;
template<> const int BookingClass::ACFirstClass::sBookingClassId = 3;
template<> const int BookingClass::ExecutiveChairCar::sBookingClassId = 4; 
template<> const int BookingClass::Sleeper::sBookingClassId =  5;
template<> const int BookingClass::FirstClass::sBookingClassId =  6;
template<> const int BookingClass::SecondSitting::sBookingClassId =  7;
//Load Factor
template<> double BookingClass::AC2Tier::sLoadFactor =  4;
template<> double BookingClass::AC3Tier::sLoadFactor =  2.5;
template<> double BookingClass::ACChairCar::sLoadFactor = 2.0;
template<> double BookingClass::ACFirstClass::sLoadFactor = 6.5;
template<> double BookingClass::ExecutiveChairCar::sLoadFactor = 5.0; 
template<> double BookingClass::Sleeper::sLoadFactor =  1.0;
template<> double BookingClass::FirstClass::sLoadFactor =  3.0;
template<> double BookingClass::SecondSitting::sLoadFactor =  0.60;
//Tatkal Load Factor
template<> double BookingClass::AC2Tier::sTatkalLoadFactor = 0.30 ;
template<> double BookingClass::AC3Tier::sTatkalLoadFactor = 0.30 ;
template<> double BookingClass::ACChairCar::sTatkalLoadFactor = 0.30 ;
template<> double BookingClass::ACFirstClass::sTatkalLoadFactor = 0.30 ;
template<> double BookingClass::ExecutiveChairCar::sTatkalLoadFactor = 0.30 ; 
template<> double BookingClass::Sleeper::sTatkalLoadFactor = 0.30 ;
template<> double BookingClass::FirstClass::sTatkalLoadFactor = 0.30 ;
template<> double BookingClass::SecondSitting::sTatkalLoadFactor = 0.10 ;
//Tatkal Min Charge
template<> double BookingClass::AC2Tier::sMinTatkalCharge = 400;
template<> double BookingClass::AC3Tier::sMinTatkalCharge = 300;
template<> double BookingClass::ACChairCar::sMinTatkalCharge = 125;
template<> double BookingClass::ACFirstClass::sMinTatkalCharge = 400;
template<> double BookingClass::ExecutiveChairCar::sMinTatkalCharge = 400; 
template<> double BookingClass::Sleeper::sMinTatkalCharge = 100;
template<> double BookingClass::FirstClass::sMinTatkalCharge = 400;
template<> double BookingClass::SecondSitting::sMinTatkalCharge = 10;
//Tatkal Max Charge
template<> double BookingClass::AC2Tier::sMaxTatkalCharge = 500;
template<> double BookingClass::AC3Tier::sMaxTatkalCharge = 400;
template<> double BookingClass::ACChairCar::sMaxTatkalCharge = 225;
template<> double BookingClass::ACFirstClass::sMaxTatkalCharge = 500;
template<> double BookingClass::ExecutiveChairCar::sMaxTatkalCharge = 500; 
template<> double BookingClass::Sleeper::sMaxTatkalCharge = 200;
template<> double BookingClass::FirstClass::sMaxTatkalCharge = 500;
template<> double BookingClass::SecondSitting::sMaxTatkalCharge = 15;
//Tatkal Min Dist
template<> double BookingClass::AC2Tier::sMinTatkalDistance = 500;
template<> double BookingClass::AC3Tier::sMinTatkalDistance = 500;
template<> double BookingClass::ACChairCar::sMinTatkalDistance = 250;
template<> double BookingClass::ACFirstClass::sMinTatkalDistance = 500;
template<> double BookingClass::ExecutiveChairCar::sMinTatkalDistance = 250; 
template<> double BookingClass::Sleeper::sMinTatkalDistance = 500;
template<> double BookingClass::FirstClass::sMinTatkalDistance = 500;
template<> double BookingClass::SecondSitting::sMinTatkalDistance = 100;
//Tiers
template<> const int BookingClass::AC2Tier::sTiers = 2;
template<> const int BookingClass::AC3Tier::sTiers = 3;
template<> const int BookingClass::ACChairCar::sTiers = 0;
template<> const int BookingClass::ACFirstClass::sTiers = 2;
template<> const int BookingClass::ExecutiveChairCar::sTiers = 0; 
template<> const int BookingClass::Sleeper::sTiers = 3;
template<> const int BookingClass::FirstClass::sTiers = 2;
template<> const int BookingClass::SecondSitting::sTiers = 0;
//Resv Charge
template<> double BookingClass::AC2Tier::sReservationCharge = 50.00 ;
template<> double BookingClass::AC3Tier::sReservationCharge = 40.00 ;
template<> double BookingClass::ACChairCar::sReservationCharge = 40.00 ;
template<> double BookingClass::ACFirstClass::sReservationCharge = 60.00 ;
template<> double BookingClass::ExecutiveChairCar::sReservationCharge = 60.00 ; 
template<> double BookingClass::Sleeper::sReservationCharge = 20.00 ;
template<> double BookingClass::FirstClass::sReservationCharge = 50.00 ;
template<> double BookingClass::SecondSitting::sReservationCharge = 15.00 ;

//UNit Testing
template<>
bool BookingClass::AC2Tier::UnitTestBookingClassNames()
{
    bool flag = 1; //Assuming no errors initially
    cout << "Doing Unit Test for class AC2Tier\n";
    if (Type().GetName() != "AC 2 Tier")
    {
        cout << "Error in Initializing name of the class\n";
        flag = 0;
    }
    if (Type().GetNumberofTiers() != 2)
    {
        cout << "Error in Getting number of Tiers,giving " << Type().GetNumberofTiers() << ", should be 2\n";
        flag = 0;
    }
    
    if (!Type().IsAC())
    {
        cout << "Error in Getting AC/Non-AC Status returning IsAC() as False while it should be True\n";
        flag = 0;
    }
    if (Type().IsSitting())
    {
        cout << "Error in Getting Sitting/Sleeping Status returning IsSitting() as True while it should be False\n";
        flag = 0;
    }
    if (Type().IsLuxury())
    {
        cout << "Error in Getting Luxury/Ordinary Status returning IsLuxury() as True while it should be False\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/AC2Tier.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<AC2Tier::Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator AC2Tier\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported in AC2Tier class\n";
    }
    cout << endl;
    return flag;
}
template<>
bool BookingClass::AC3Tier::UnitTestBookingClassNames()
{
    bool flag = 1; //Assuming no errors initially
    cout << "Doing Unit Test for class AC3Tier\n";
    if (Type().GetName() != "AC 3 Tier")
    {
        cout << "Error in Initializing name of the class\n";
        flag = 0;
    }
    if (Type().GetNumberofTiers() != 3)
    {
        cout << "Error in Getting number of Tiers,giving " << Type().GetNumberofTiers() << ", should be 3\n";
        flag = 0;
    }
    
    if (!Type().IsAC())
    {
        cout << "Error in Getting AC/Non-AC Status returning IsAC() as False while it should be True\n";
        flag = 0;
    }
    if (Type().IsSitting())
    {
        cout << "Error in Getting Sitting/Sleeping Status returning IsSitting() as True while it should be False\n";
        flag = 0;
    }
    if (Type().IsLuxury())
    {
        cout << "Error in Getting Luxury/Ordinary Status returning IsLuxury() as True while it should be False\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/AC3Tier.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<AC3Tier::Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator AC3Tier\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported in AC3Tier class\n";
    }
    cout << endl;
    return flag;
}
template<>
bool BookingClass::ACChairCar::UnitTestBookingClassNames()
{
    bool flag = 1; //Assuming no errors initially
    cout << "Doing Unit Test for class ACChairCar\n";
    if (Type().GetName() != "AC Chair Car")
    {
        cout << "Error in Initializing name of the class\n";
        flag = 0;
    }
    if (Type().GetNumberofTiers() != 0)
    {
        cout << "Error in Getting number of Tiers,giving " << Type().GetNumberofTiers() << ", should be 0\n";
        flag = 0;
    }
   
    if (!Type().IsAC())
    {
        cout << "Error in Getting AC/Non-AC Status returning IsAC() as False while it should be True\n";
        flag = 0;
    }
    if (!Type().IsSitting())
    {
        cout << "Error in Getting Sitting/Sleeping Status returning IsSitting() as False while it should be True\n";
        flag = 0;
    }
    if (Type().IsLuxury())
    {
        cout << "Error in Getting Luxury/Ordinary Status returning IsLuxury() as True while it should be False\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/ACChairCar.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<ACChairCar::Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator ACChairCar\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported in ACChairCar class\n";
    }
    cout << endl;
    return flag;
}
template<>
bool BookingClass::ACFirstClass::UnitTestBookingClassNames()
{
    bool flag = 1; //Assuming no errors initially
    cout << "Doing Unit Test for class ACFirstClass\n";
    if (Type().GetName() != "AC First Class")
    {
        cout << "Error in Initializing name of the class\n";
        flag = 0;
    }
    if (Type().GetNumberofTiers() != 2)
    {
        cout << "Error in Getting number of Tiers,giving " << Type().GetNumberofTiers() << ", should be 2\n";
        flag = 0;
    }
    
    if (!Type().IsAC())
    {
        cout << "Error in Getting AC/Non-AC Status returning IsAC() as False while it should be True\n";
        flag = 0;
    }
    if (Type().IsSitting())
    {
        cout << "Error in Getting Sitting/Sleeping Status returning IsSitting() as True while it should be False\n";
        flag = 0;
    }
    if (!Type().IsLuxury())
    {
        cout << "Error in Getting Luxury/Ordinary Status returning IsLuxury() as False while it should be True\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/ACFirstClass.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<ACFirstClass::Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator ACFirstClass\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported in ACFirstClass class\n";
    }
    cout << endl;
    return flag;
}
template<>
bool BookingClass::FirstClass::UnitTestBookingClassNames()
{
    bool flag = 1; //Assuming no errors initially
    cout << "Doing Unit Test for class FirstClass\n";
    if (Type().GetName() != "First Class")
    {
        cout << "Error in Initializing name of the class\n";
        flag = 0;
    }
    if (Type().GetNumberofTiers() != 2)
    {
        cout << "Error in Getting number of Tiers,giving " << Type().GetNumberofTiers() << ", should be 2\n";
        flag = 0;
    }
    
    if (Type().IsAC())
    {
        cout << "Error in Getting AC/Non-AC Status returning IsAC() as True while it should be False\n";
        flag = 0;
    }
    if (Type().IsSitting())
    {
        cout << "Error in Getting Sitting/Sleeping Status returning IsSitting() as True while it should be False\n";
        flag = 0;
    }
    if (!Type().IsLuxury())
    {
        cout << "Error in Getting Luxury/Ordinary Status returning IsLuxury() as False while it should be True\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/FirstClass.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<FirstClass::Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator FirstClass\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported in FirstClass class\n";
    }
    cout << endl;
    return flag;
}
template<>
bool BookingClass::Sleeper::UnitTestBookingClassNames()
{
    bool flag = 1; //Assuming no errors initially
    cout << "Doing Unit Test for class Sleeper\n";
    if (Type().GetName() != "Sleeper")
    {
        cout << "Error in Initializing name of the class\n";
        flag = 0;
    }
    if (Type().GetNumberofTiers() != 3)
    {
        cout << "Error in Getting number of Tiers,giving " << Type().GetNumberofTiers() << ", should be 3\n";
        flag = 0;
    }
    
    if (Type().IsAC())
    {
        cout << "Error in Getting AC/Non-AC Status returning IsAC() as True while it should be False\n";
        flag = 0;
    }
    if (Type().IsSitting())
    {
        cout << "Error in Getting Sitting/Sleeping Status returning IsSitting() as True while it should be False\n";
        flag = 0;
    }
    if (Type().IsLuxury())
    {
        cout << "Error in Getting Luxury/Ordinary Status returning IsLuxury() as True while it should be False\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/Sleeper.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator Sleeper\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported in Sleeper class\n";
    }
    cout << endl;
    return flag;
}
template<>
bool BookingClass::SecondSitting::UnitTestBookingClassNames()
{
    bool flag = 1;//Assuming no errors initially
    cout<<"Doing Unit Test for class SecondSitting\n";
    if(Type().GetName()!="Second Sitting")
    {
        cout<<"Error in Initializing name of the class\n";
        flag = 0;
    }
    if(Type().GetNumberofTiers()!=0)
    {
        cout<<"Error in Getting number of Tiers,giving "<<Type().GetNumberofTiers()<<", should be 0\n";
        flag = 0;
    }
    
    if(Type().IsAC())
    {
        cout<<"Error in Getting AC/Non-AC Status returning IsAC() as True while it should be False\n";
        flag = 0;
    }
    if(!Type().IsSitting())
    {
        cout<<"Error in Getting Sitting/Sleeping Status returning IsSitting() as False while it should be True\n";
        flag = 0;
    }
    if(Type().IsLuxury())
    {
        cout<<"Error in Getting Luxury/Ordinary Status returning IsLuxury() as True while it should be False\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/SS.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator SecondSitting\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors reported in SecondSitting class\n";
    }
    cout<<endl;
    return flag;
}

template<>
bool BookingClass::ExecutiveChairCar::UnitTestBookingClassNames()
{
    bool flag = 1;//Assuming no errors initially
    cout<<"Doing Unit Test for class SecondSitting\n";
    if(Type().GetName()!="Executive Chair Car")
    {
        cout<<"Error in Initializing name of the class\n";
        flag = 0;
    }
    if(Type().GetNumberofTiers()!=0)
    {
        cout<<"Error in Getting number of Tiers,giving "<<Type().GetNumberofTiers()<<", should be 0\n";
        flag = 0;
    }
    
    if(!Type().IsAC())
    {
        cout<<"Error in Getting AC/Non-AC Status returning IsAC() as False while it should be True\n";
        flag = 0;
    }
    if(!Type().IsSitting())
    {
        cout<<"Error in Getting Sitting/Sleeping Status returning IsSitting() as False while it should be True\n";
        flag = 0;
    }
    if(!Type().IsLuxury())
    {
        cout<<"Error in Getting Luxury/Ordinary Status returning IsLuxury() as False while it should be True\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/ExecutiveChairCar.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator SecondSitting\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors reported in ExecutiveiveChairCar class\n";
    }
    cout<<endl;
    return flag;
}


bool BookingClass::UnitTestBookingClass()
{
    bool flag = 1;//Assuming no errors initially
    cout<<"Doing Unit Test for class BookingClass\n";
    if(BookingClass::ExecutiveChairCar::Type().GetName()!="Executive Chair Car")
    {
        cout<<"Error in Initializing name of the class\n";
        flag = 0;
    }
    if(BookingClass::ExecutiveChairCar::Type().GetNumberofTiers()!=0)
    {
        cout<<"Error in Getting number of Tiers,giving "<<BookingClass::ExecutiveChairCar::Type().GetNumberofTiers()<<", should be 0\n";
        flag = 0;
    }
    
    if(!BookingClass::ExecutiveChairCar::Type().IsAC())
    {
        cout<<"Error in Getting AC/Non-AC Status returning IsAC() as False while it should be True\n";
        flag = 0;
    }
    if(!BookingClass::ExecutiveChairCar::Type().IsSitting())
    {
        cout<<"Error in Getting Sitting/Sleeping Status returning IsSitting() as False while it should be True\n";
        flag = 0;
    }
    if(!BookingClass::ExecutiveChairCar::Type().IsLuxury())
    {
        cout<<"Error in Getting Luxury/Ordinary Status returning IsLuxury() as False while it should be True\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/ExecutiveChairCar.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<BookingClass::ExecutiveChairCar::Type();
    string op = ss.str();
    
    if(op!=golden)
    {
        cout<<"Error in output stream operator ExecutiveChairCar\n";
        cout<<"Expected:\n";
        cout<<golden<<endl;
        cout<<"Output:\n";
        cout<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors reported in ExecutiveiveChairCar class\n";
    }
    cout<<endl;
    return flag;
}