#include "concessions.h"

#ifndef LADIES_CONS_INC
#define LADIES_CONS_INC
class LadiesConcession :public Concessions
{
    const static double sladiesConcession;
    public:
    static bool UnitTestLadiesConcession();
    LadiesConcession();
    ~LadiesConcession();
};
#endif