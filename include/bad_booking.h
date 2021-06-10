#include <exception>
#include <iostream>
using namespace std;
#ifndef BAD_BOOKING
#define BAD_BOOKING

class Bad_Booking : public exception
{
    string err_msg_;

public:
    Bad_Booking(string err_msg="Invalid Booking");
    ~Bad_Booking() throw();
    inline const char *what() const throw() { return err_msg_.c_str(); }
};

class Bad_Booking_date : public Bad_Booking
{
public:
    Bad_Booking_date();
    ~Bad_Booking_date() throw();    
};

class Bad_Booking_st : public Bad_Booking  //Invalid Category
{
public:
    Bad_Booking_st();
    ~Bad_Booking_st() throw();    
};

class Bad_Booking_passenger : public Bad_Booking  //Invalid Category
{
public:
    Bad_Booking_passenger();
    ~Bad_Booking_passenger() throw();    
};


#endif