#include "../include/genderTypes.h"

template <>
const string Gender::Male::sName = "Male";
template <>
const string Gender::Female::sName = "Female";
template <>
const double Gender::Male::sSrCitizenConcession = 0.4;
template <>
const double Gender::Female::sSrCitizenConcession = 0.5;
template<>
bool Gender::Female::UnitTestGenderType()
{
    cout<<"Doing Uni Testing For Gender::Female Class\n";
    int flag = 1;
    if(Gender::Female::Type().getName()!="Female")
    {
        cout<<"Error in Initializing Female Type";
        flag=0;
    }
    //Testing get concession
    if(Gender::Female::Type().getSrCitizenConcession()!=0.5)
    {
        cout<<"Error in storing Female senior Citizen Concession";
        flag = 0;
    }
    //Testing OP stream operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/female.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<Gender::Female::Type();          
    string op = ss.str();
    if(op!=golden)
    {
        cout<<"Error in Gender OP stream operator\n";
        cout<<"Expected:\n"<<golden<<endl;
        cout<<"Output:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors reported for Gender::Female Class\n";
    }
    cout<<endl;
    return flag;
}
template<>
bool Gender::Male::UnitTestGenderType()
{
    cout<<"Doing Uni Testing For Gender::Female Class\n";
    int flag = 1;
    if(Gender::Male::Type().getName()!="Male")
    {
        cout<<"Error in Initializing Male Type";
        flag=0;
    }
    //Testing get concession
    if(Gender::Male::Type().getSrCitizenConcession()!=0.4)
    {
        cout<<"Error in storing Male senior Citizen Concession";
        flag = 0;
    }
    //Testing OP stream operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/male.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<Gender::Male::Type();          
    string op = ss.str();
    if(op!=golden)
    {
        cout<<"Error in Gender OP stream operator\n";
        cout<<"Expected:\n"<<golden<<endl;
        cout<<"Output:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors reported for Gender::Male Class\n";
    }
    cout<<endl;
    return flag;
}

bool Gender::UnitTestGender()
{
    cout<<"Doing Uni Testing For Gender Class\n";
    int flag = 1;
    if(Gender::Male::Type().getName()!="Male")
    {
        cout<<"Error in Initializing Male Type";
        flag=0;
    }
    if(Gender::Female::Type().getName()!="Female")
    {
        cout<<"Error in Initializing Female Type";
        flag=0;
    }
    if(Gender::Male::Type().getSrCitizenConcession()!=0.4)
    {
        cout<<"Error in storing Male senior Citizen Concession";
        flag = 0;
    }
    if(Gender::Female::Type().getSrCitizenConcession()!=0.5)
    {
        cout<<"Error in storing Female senior Citizen Concession";
        flag = 0;
    }
    //Testing OP stream operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/gender.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss<<Gender::Male::Type()<<endl;
    ss<<Gender::Female::Type()<<endl;      
    string op = ss.str();
    if(op!=golden)
    {
        cout<<"Error in Gender OP stream operator\n";
        cout<<"Expected:\n"<<golden<<endl;
        cout<<"Output:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors reported for Gender Class\n";
    }
    cout<<endl;
    return flag;
}

/**
int main()
{
    cout<<Gender::Male::Type().getName()<<endl;
    return 0;
}*/