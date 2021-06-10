#include "../include/ladiesConcessions.h"
const double LadiesConcession::sladiesConcession = 0.0;
LadiesConcession::LadiesConcession() : Concessions(LadiesConcession::sladiesConcession) {}
LadiesConcession::~LadiesConcession() {}

bool LadiesConcession::UnitTestLadiesConcession()
{
    cout<<"Doing Unit Testing For Ladies Concessions Class\n";
    int flag = 1;
    LadiesConcession Cons;
    if(abs(Cons.concession_)>0.001)
    {
        cout<<"Error in Ladies Concession\n";
        flag=0;
    }    
    if(flag)
    {
        cout<<"No Errors reported for Ladies Concessions Class\n";
    }
    cout<<endl;
    return flag;
}