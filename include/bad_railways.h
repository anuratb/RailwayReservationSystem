#include <exception>
#include <iostream>
using namespace std;
#ifndef BAD_RAILWAYS
#define BAD_RAILWAYS

class Bad_Railways : public exception
{
    string err_msg_;

public:
    Bad_Railways(string mess ="Invalid Railways"); // :err_msg("Invalid Railways") {}
    ~Bad_Railways() throw();
    inline const char *what() const throw() { return err_msg_.c_str(); }
};

class Bad_Railways_dupSt : public Bad_Railways
{
public:
    Bad_Railways_dupSt(); // :err_msg("Invalid Railways") {}
    ~Bad_Railways_dupSt() throw();    
};

class Bad_Railways_dupDist : public Bad_Railways
{
public:
    Bad_Railways_dupDist(); // :err_msg("Invalid Railways") {}
    ~Bad_Railways_dupDist() throw();    
};

#endif