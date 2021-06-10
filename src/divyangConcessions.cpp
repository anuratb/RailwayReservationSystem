#include "../include/divyangConcessions.h"
DivyangConcession::DivyangConcession(const Passenger& P,const BookingClass & B) :Concessions(P.getDisabiltiyType()->GetConcession(B.GetClassId())) {}
DivyangConcession::~DivyangConcession() {}

bool DivyangConcession::UnitTestDivyangConcession()
{
    cout<<"Doing Unit Testing For Divyang Concessions Class\n";
    int flag = 1;
    Passenger *P = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
    DivyangConcession Cons(*P,BookingClass::ACChairCar::Type());
    DivyangConcession Cons2(*P,BookingClass::AC2Tier::Type());
    if(Cons.concession_ >0.751||Cons.concession_<0.749)
    {
        cout<<"Error in Divyang Concession\n";
        flag=0;
    }    
    if(Cons2.concession_ >0.501||Cons.concession_<0.449)
    {
        cout<<"Error in Divyang Concession\n";
        flag=0;
    }   
    if(flag)
    {
        cout<<"No Errors reported for Divyang Concessions Class\n";
    }
    cout<<endl;
    delete P;
    return flag;
}