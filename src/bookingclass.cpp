/**
 * @file bookingclass.cpp
 * @author Anurat Bhattacharya
 * @brief BookingClass Implementation
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include "../include/bookingclass.h"
BookingClass::BookingClass(string nme,int id) : name_(nme),id_(id) {}                             //Constructor
BookingClass::BookingClass(const BookingClass &other) : name_(other.name_),id_(other.id_) {}      //CCR
BookingClass &BookingClass::operator=(const BookingClass &other) { return *this; } //Blocked
BookingClass::~BookingClass() {}
ostream &operator<<(ostream &os, const BookingClass &obj)
{
    os << obj.GetName() << endl;
    os << " : Mode: " << (obj.IsSitting() ? "Sitting" : "Sleeping") << endl;
    os << " : Comfort: " << (obj.IsAC() ? "AC" : "Non-AC") << endl;
    os << " : Bunks: " << obj.GetNumberofTiers() << endl;
    os << " : Luxury: " << (obj.IsLuxury() ? "Yes" : "No") << endl;
    return os;
}
