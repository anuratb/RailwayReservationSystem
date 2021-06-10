#include "concessions.h"
#include "passenger.h"
#ifndef SRCITIZEN_CONS_INC
#define SRCITIZEN_CONS_INC
class SrCitizenConcession :public Concessions
{
    public:
    static bool UnitTestSrCitizenConcession(); 
    SrCitizenConcession(const Passenger& P);
    ~SrCitizenConcession();
    
};
#endif