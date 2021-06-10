#include "../include/gender.h"

Gender::Gender(string nme, double val) : genderName_(nme), SrCitizenConcession_(val) {}
Gender::~Gender() {}

ostream &operator<<(ostream& os,const Gender& obj) 
{
    os << obj.getName();
    return os;
}