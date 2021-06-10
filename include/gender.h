/**
 * @file gender.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief 
 * @version 0.1
 * @date 2021-04-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

#ifndef Gender_INC
#define Gender_INC

template <typename T> 
class GenderTypes;

class Gender{

    struct Male_{};
    struct Female_{};
protected:
    const string genderName_;
    const double SrCitizenConcession_;
    Gender(string nme,double val);
    virtual ~Gender();
public:
    inline string getName() const {return genderName_;}
    friend  ostream& operator<<(ostream& os,const Gender& obj)   ;
    inline double getSrCitizenConcession() const {return SrCitizenConcession_;}
    typedef GenderTypes<Male_> Male;
    typedef GenderTypes<Female_> Female;
    static bool UnitTestGender();
};
#endif