#include "concessions.h"

#ifndef GEN_CONS_INC
#define GEN_CONS_INC
class GeneralConcession :public Concessions
{
    const static double sgenConcession;
    GeneralConcession();
    ~GeneralConcession();
    public:    
    static bool UnitTestGeneralConcession();
    static const GeneralConcession & Type();
    
};
#endif