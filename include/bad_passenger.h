#include <exception>
#include <iostream>
using namespace std;
#ifndef BAD_PASSENGER
#define BAD_PASSENGER

class Bad_Passenger : public exception
{
    string err_msg_;

public:
    Bad_Passenger(string mess="Invalid Passenger"); // :err_msg("Invalid Passenger") {}
    ~Bad_Passenger() throw();
    inline const char *what() const throw() { return err_msg_.c_str(); }
};

class Bad_Passenger_name : public Bad_Passenger
{
public:
    Bad_Passenger_name(); 
    ~Bad_Passenger_name() throw();    
};

class Bad_Passenger_age :public  Bad_Passenger
{
public:
    Bad_Passenger_age(); 
    ~Bad_Passenger_age() throw();    
};

class Bad_Passenger_aadhar :public Bad_Passenger
{
public:
    Bad_Passenger_aadhar(); 
    ~Bad_Passenger_aadhar() throw();    
};

class Bad_Passenger_mobile :public Bad_Passenger
{
public:
    Bad_Passenger_mobile(); 
    ~Bad_Passenger_mobile() throw();    
};

class Bad_Passenger_divyang :public Bad_Passenger
{
public:
    Bad_Passenger_divyang(string err_msg = "Inconsistent Divyang Details"); 
    ~Bad_Passenger_divyang() throw();    
};
#endif