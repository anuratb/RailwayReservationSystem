#include <iostream>
#include <string>
#include "gender.h"
using namespace std;

#ifndef GENDERTYPES_INC
#define GENDERTYPES_INC

template <typename T>
class GenderTypes : public Gender
{
    GenderTypes(string nme = GenderTypes<T>::sName, double cons = GenderTypes<T>::sSrCitizenConcession) : Gender(nme, cons) {}
    ~GenderTypes() {}
    static const string sName;
    static const double sSrCitizenConcession;

public:
    static const GenderTypes<T> &Type()
    {
        static const GenderTypes<T> Obj;
        return Obj;
    }
    static bool UnitTestGenderType();
};
#endif