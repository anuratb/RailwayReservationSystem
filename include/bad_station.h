#include <exception>
#include <iostream>
using namespace std;
#ifndef BAD_STATION
#define BAD_STATION

class Bad_Station : public exception
{
    string err_msg_;

public:
    Bad_Station(); // :err_msg("Invalid Station") {}
    ~Bad_Station() throw();
    inline const char *what() const throw() { return err_msg_.c_str(); }
};
#endif