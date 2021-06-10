#include "../include/DivyangNames.h"

template<> const string Divyang::Blind::sDivyangName = "Blind";
template<> const string Divyang::Ortho::sDivyangName = "Ortho";
template<> const string Divyang::Cancer::sDivyangName = "Cancer";
template<> const string Divyang::Tb::sDivyangName = "Tb";

template<> const vector<double> Divyang::Blind::sDivyangCons = vector<double>({0.50,0.75,0.75,0.50,0.75,0.75,0.75,0.75});
template<> const vector<double> Divyang::Ortho::sDivyangCons = vector<double>({0.50,0.75,0.75,0.50,0.75,0.75,0.75,0.75});
template<> const vector<double> Divyang::Cancer::sDivyangCons = vector<double>({0.5,1.00,1.00,0.50,0.75,1.00,0.75,1.00});
template<> const vector<double> Divyang::Tb::sDivyangCons = vector<double>({0.00,0.00,0.00,0.00,0.00,0.75,0.75,0.75});



template<>
bool Divyang::Blind::UnitTestingDivyangNames()
{
    bool flag = 1;
    cout<<"Doing unit Testing for Divyang::Blind\n";
    if(Blind::Type().getDivyangName()!="Blind")
    {
        cout<<"Error in Blind Class Name\n";
        flag = 0;
    }
       
    if((Blind::Type().GetConcession(0)>0.5001)||(Blind::Type().GetConcession(0)<0.4999))
    {
        cout<<"Error In getting Concession of Blind wrt AC2Tier\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test For Blind Passed"<<endl;
    }
    cout<<endl;
    return flag;
}
template<>
bool Divyang::Ortho::UnitTestingDivyangNames()
{
    bool flag = 1;
    cout<<"Doing unit Testing for Divyang::Ortho\n";
    if(Ortho::Type().getDivyangName()!="Ortho")
    {
        cout<<"Error in Ortho Class Name\n";
        flag = 0;
    }
       
    if((Ortho::Type().GetConcession(0)>0.5001)||(Ortho::Type().GetConcession(0)<0.4999))
    {
        cout<<"Error In getting Concession of Ortho wrt AC2Tier\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test For Ortho Passed"<<endl;
    }
    cout<<endl;
    return flag;
}
template<>
bool Divyang::Cancer::UnitTestingDivyangNames()
{
    bool flag = 1;
    cout<<"Doing unit Testing for Divyang::Cancer\n";
    if(Cancer::Type().getDivyangName()!="Cancer")
    {
        cout<<"Error in Cancer Class Name\n";
        flag = 0;
    }
       
    if((Cancer::Type().GetConcession(0)>0.5001)||(Cancer::Type().GetConcession(0)<0.4999))
    {
        cout<<"Error In getting Concession of Cancer wrt AC2Tier\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test For Cancer Passed"<<endl;
    }
    cout<<endl;
    return flag;
}
template<>
bool Divyang::Tb::UnitTestingDivyangNames()
{
    bool flag = 1;
    cout<<"Doing unit Testing for Divyang::Tb\n";
    if(Tb::Type().getDivyangName()!="Tb")
    {
        cout<<"Error in Tb Class Name\n";
        flag = 0;
    }    
    if((abs((Divyang::Tb::Type().GetConcession(0))) >0.0001))
    {
        cout<<"Error In getting Concession of Tb wrt AC2Tier\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test For Tb Passed"<<endl;
    }
    cout<<endl;
    return flag;
}

bool Divyang::UnitTestDivyang()
{
    bool flag = 1;
    cout<<"Doing unit Testing for Divyang\n";
    if(Divyang::Tb::Type().getDivyangName()!="Tb")
    {
        cout<<"Error in Tb Class Name\n";
        flag = 0;
    }
       
    if((abs((Divyang::Tb::Type().GetConcession(0))) >0.0001))
    {
        cout<<"Error In getting Concession of Tb wrt AC2Tier\n";
        flag = 0;
    }
    if(flag)
    {
        cout<<"Unit Test For Divyang Passed"<<endl;
    }
    cout<<endl;
    return flag;
}