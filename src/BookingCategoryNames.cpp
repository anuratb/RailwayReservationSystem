
#include "../include/BookingCategoryNames.h"

template<>const string BookingCategory::General::sCategoryName = "General";
template<>const string BookingCategory::SeniorCitizen::sCategoryName = "Senior Citizen";
template<>const string BookingCategory::Divyang::sCategoryName = "Divyang";
template<>const string BookingCategory::Ladies::sCategoryName = "Ladies";
template<>const string BookingCategory::Tatkal::sCategoryName = "Tatkal";
template<>const string BookingCategory::PremiumTatkal::sCategoryName = "PremiumTatkal";

template<>const double BookingCategory::General::spFactor = 0;
template<>const double BookingCategory::SeniorCitizen::spFactor = 0;
template<>const double BookingCategory::Divyang::spFactor = 0;
template<>const double BookingCategory::Ladies::spFactor = 0;
template<>const double BookingCategory::Tatkal::spFactor = 1;
template<>const double BookingCategory::PremiumTatkal::spFactor = 2;

template<>double BookingCategory::General::getConcession(const Passenger &P, const BookingClass &B) const
{
    return GeneralConcession::Type().getConcession();

}
template<>double BookingCategory::SeniorCitizen::getConcession(const Passenger &P, const BookingClass &B) const
{
    return SrCitizenConcession(P).getConcession();
}
template<>double BookingCategory::Divyang::getConcession(const Passenger &P, const BookingClass &B) const
{
    return DivyangConcession(P,B).getConcession();
}
template<>double BookingCategory::Ladies::getConcession(const Passenger &P, const BookingClass &B) const
{
    return LadiesConcession().getConcession();
}
template<>double BookingCategory::Tatkal::getConcession(const Passenger &P, const BookingClass &B) const
{
    return 0.0;
}
template<>double BookingCategory::PremiumTatkal::getConcession(const Passenger &P, const BookingClass &B) const
{
    return 0.0;
}


template<>bool BookingCategory::General::getEligibility(const Passenger &P) const
{
    return 1;

}
template<>bool BookingCategory::SeniorCitizen::getEligibility(const Passenger &P) const
{
    if(P.getGender().getName()=="Male"&&P.getAge()>=60)
    {
        return 1;
    }
    else if(P.getGender().getName()=="Female"&&P.getAge()>=58)
    {
        return 1;
    }
    return 0;
}
template<>bool BookingCategory::Divyang::getEligibility(const Passenger &P) const
{
    if(P.getDisabiltiyType()==NULL)
    {
        return 0;
    }
    return 1;
}
template<>bool BookingCategory::Ladies::getEligibility(const Passenger &P) const
{
    return P.getGender().getName()=="Female";
}
template<>bool BookingCategory::Tatkal::getEligibility(const Passenger &P) const
{
    return 1;
}
template<>bool BookingCategory::PremiumTatkal::getEligibility(const Passenger &P) const
{
    return 1;
}

template<>
bool BookingCategory::General::UnitTestCategoryNames(Passenger *P,Passenger *P1){   
    //P should be Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
    bool flag = 1;
    cout<<"Doing unit Testing for General Booking Category\n";
    if(General::Type().getCategoryName()!="General")
    {
        cout<<"Error in Generel Category\n";
        flag = 0;
    }
    if(!General::Type().getEligibility(*P))
    {
        cout<<"Error in getting Eleigibility of General Passenger\n";
        flag = 0;
    }    
    if(abs(General::Type().getConcession(*P,BookingClass::AC2Tier::Type()))>0.0001)
    {
        cout<<"Error In getting Concession of General Passenger\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Testing for general Booking Category Passed\n";
    }
    cout<<endl;
    return flag;
}

template<>
bool BookingCategory::Ladies::UnitTestCategoryNames(Passenger *P,Passenger* P1){   
    //P should be Passenger::CreatePassenger("875496235412", "9/10/1976", Gender::Female::Type(), "4512369875", "Padme", "", "Amidala");
    //P1 should be male
    bool flag = 1;
    cout<<"Doing unit Testing for Ladies Booking Category\n";
    if(Ladies::Type().getCategoryName()!="Ladies")
    {
        cout<<"Error in Ladies Category\n";
        flag = 0;
    }
    if(!Ladies::Type().getEligibility(*P))
    {
        cout<<"Error in getting Eligibility of Ladies Passenger\n";
        flag = 0;
    }    
    if(Ladies::Type().getEligibility(*P1))
    {
        cout<<"Error in getting Eligibility of Ladies Passenger\n";
        flag = 0;
    }  
    if(abs(Ladies::Type().getConcession(*P,BookingClass::AC2Tier::Type()))>0.0001)
    {
        cout<<"Error In getting Concession of Ladies Passenger\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test for Ladies Booking Category PAssed\n";
    }
    cout<<endl;
    return flag;
}

template<>
bool BookingCategory::Divyang::UnitTestCategoryNames(Passenger *P,Passenger *P1){   
    //P should be Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type())
    //P1 should be non divyang
    bool flag = 1;
    cout<<"Doing unit Testing for Divyang Booking Category\n";
    if(Divyang::Type().getCategoryName()!="Divyang")
    {
        cout<<"Error in Divyang Category\n";
        flag = 0;
    }
    if(!Divyang::Type().getEligibility(*P))
    {
        cout<<"Error in getting Eligibility of Divyang Passenger\n";
        flag = 0;
    }   
    if(Divyang::Type().getEligibility(*P1))
    {
        cout<<"Error in getting Eligibility of Divyang Passenger\n";
        flag = 0;
    } 
    if((Divyang::Type().getConcession(*P,BookingClass::AC2Tier::Type())>0.5001)||(Divyang::Type().getConcession(*P,BookingClass::AC2Tier::Type())<0.4999))
    {
        cout<<"Error In getting Concession of Divyang Passenger\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test for Divyang Booking Cat Passed\n ";
    }
    cout<<endl;
    return flag;
}

template<>
bool BookingCategory::SeniorCitizen::UnitTestCategoryNames(Passenger *P,Passenger *P1){   
    //P should be Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda")
    //P1 should be non senior citizen
    bool flag = 1;
    cout<<"Doing unit Testing for Sr Citizen Booking Category\n";
    if(SeniorCitizen::Type().getCategoryName()!="Senior Citizen")
    {
        cout<<"Error in Sr Citizen Category Name\n";
        flag = 0;
    }
    if(!SeniorCitizen::Type().getEligibility(*P))
    {
        cout<<"Error in getting Eligibility of Sr. Citizen Passenger\n";
        flag = 0;
    }  
    if(SeniorCitizen::Type().getEligibility(*P1))
    {
        cout<<"Error in getting Eligibility of Sr. Citizen Passenger\n";
        flag = 0;
    }   
    if((SeniorCitizen::Type().getConcession(*P,BookingClass::AC2Tier::Type())>0.4001)||(SeniorCitizen::Type().getConcession(*P,BookingClass::AC2Tier::Type())<0.3999))
    {
        cout<<"Error In getting Concession of Senior Citizen Passenger\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test For Senior Citizen Passed"<<endl;
    }
    cout<<endl;
    return flag;
}

bool BookingCategory::UnitTestBookingCategory(Passenger *P){   
    //P should be Passenger::CreatePassenger("425631458963", "2/5/1901", Gender::Male::Type(), "9433162841", "", "", "Yoda")
    bool flag = 1;
    cout<<"Doing unit Testing for  Booking Category\n";
    if(SeniorCitizen::Type().getCategoryName()!="Senior Citizen")
    {
        cout<<"Error in Sr Citizen Category Name\n";
        flag = 0;
    }
    if(!SeniorCitizen::Type().getEligibility(*P))
    {
        cout<<"Error in getting Eligibility of Sr. Citizen Passenger\n";
        flag = 0;
    }    
    if((SeniorCitizen::Type().getConcession(*P,BookingClass::AC2Tier::Type())>0.4001)||(SeniorCitizen::Type().getConcession(*P,BookingClass::AC2Tier::Type())<0.3999))
    {
        cout<<"Error In getting Concession of Senior Citizen Passenger\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test For Booking Category Passed"<<endl;
    }
    cout<<endl;
    return flag;
}