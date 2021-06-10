#include <exception>
#include <iostream>
using namespace std;
#ifndef BAD_DATE
#define BAD_DATE

class Bad_Date : public exception
{
    string err_msg_;

public:
    Bad_Date(string mess="Invalid Date"); // :err_msg("Invalid Date") {} TODO
    ~Bad_Date() throw();
    inline const char *what() const throw() { return err_msg_.c_str(); }
};
#endif