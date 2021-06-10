/**
 * @file passenger.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief 
 * @version 0.1
 * @date 2021-03-06
 *
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include "date.h"
#include "gender.h"
#include "genderTypes.h"
#include "Divyang.h"
#include "DivyangNames.h"
#include "bad_passenger.h"
using namespace std;
#ifndef Passenger_INC
#define Passenger_INC

class Passenger
{
    struct Name
    {
        string firstName;
        string middleName;
        string lastName;
    };
    Name name_;            //Name of Passenger
    string aadharNo_;      //Aadhar number
    Date dob_;             //Date of Birth
    const Gender &gender_; //  Gender M/F
    string mob_;           //mobile number
    string disabilityID_;
    const Divyang *const disabilityType_;                                                                                                                                                       //Gen,Ladies,SrCitizen,Divyang,Tatkal,PremiumTatkal
    Passenger(string aadhar, const Date& dob, const Gender &gender, string mob, string firstName, string middleName, string lastName, string dsablity_id = "", const Divyang *disabilityType_ = NULL); //Costructor

    friend ostream &operator<<(ostream &os, const Passenger &); //Stream operator
    Passenger &operator=(const Passenger &other); //CAO
public:
    
    inline const Gender &getGender() const { return gender_; }
    int getAge() const; //TO get Age
    inline const Divyang *const getDisabiltiyType() const { return disabilityType_; }
    static Passenger* CreatePassenger(string aadhar, string dob, const Gender &gender, string mob, string firstName, string middleName, string lastName, string dsablity_id = "", const Divyang *disabilityType_ = NULL); //To create a pasenger and return it
    Passenger(const Passenger &other);                                                                                                                                                                                  //CAO
    static bool UnitTestPassenger();                                                                                                                                                                                    //Unit Testing
};
#endif