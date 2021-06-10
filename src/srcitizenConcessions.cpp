#include "../include/srcitizenConcessions.h"

SrCitizenConcession::SrCitizenConcession(const Passenger &P) :Concessions(P.getGender().getSrCitizenConcession()) {}

SrCitizenConcession::~SrCitizenConcession() {}

bool SrCitizenConcession::UnitTestSrCitizenConcession()
{
    cout<<"Doing Unit Testing For Sr Citizen Concessions Class\n";
    int flag = 1;
    Passenger *P1 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
    Passenger *P2 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
    SrCitizenConcession Cons1(*P1);
    SrCitizenConcession Cons2(*P2);
    if((Cons1.concession_ >0.401||Cons1.concession_<0.399)||(Cons2.concession_ >0.501||Cons2.concession_<0.499))
    {
        cout<<"Error in Senior Citizen Concession\n";
        flag=0;
    }    
    if(flag)
    {
        cout<<"No Errors reported for Senior Citizen Concessions Class\n";
    }
    cout<<endl;
    delete P1;
    delete P2;
    return flag;
}

bool Concessions::UnitTestConcession()
{
    cout<<"Doing Unit Testing For Concessions Class\n";
    int flag = 1;
    Passenger *P1 = Passenger::CreatePassenger("412875496523", "5/12/1990", Gender::Male::Type(), "4125896541", "Kannan", "", "Jarrus", "4512", &Divyang::Blind::Type());
    Passenger *P2 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
    SrCitizenConcession Cons1(*P1);
    SrCitizenConcession Cons2(*P2);
    if((Cons1.concession_ >0.401||Cons1.concession_<0.399)||(Cons2.concession_ >0.501||Cons2.concession_<0.499))
    {
        cout<<"Error in Concession Class\n";
        flag=0;
    }    
    if(flag)
    {
        cout<<"No Errors reported for Concessions Class\n";
    }
    cout<<endl;
    delete P1;
    delete P2;
    return flag;
}
