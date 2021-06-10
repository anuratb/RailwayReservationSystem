#include "../include/genConcessions.h"
const double GeneralConcession::sgenConcession = 0.0;
GeneralConcession::GeneralConcession() : Concessions(GeneralConcession::sgenConcession) {}
GeneralConcession::~GeneralConcession() {}

const GeneralConcession & GeneralConcession::Type()
{
    static const GeneralConcession Obj;
    return Obj;
}
bool GeneralConcession::UnitTestGeneralConcession()
{
    
    cout<<"Doing Unit Testing For General Concessions Class\n";
    int flag = 1;
    if(abs(GeneralConcession::Type().concession_)>0.001)
    {
        cout<<"Error in General Concession\n";
        flag=0;
    }    
    if(flag)
    {
        cout<<"No Errors reported for General Concessions Class\n";
    }
    cout<<endl;
    return flag;

}