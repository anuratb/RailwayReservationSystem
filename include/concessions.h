/**
 * @file concessions.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief Concessions Class
 * @version 0.1
 * @date 2021-03-29
 *  
 */
#ifndef CONCESSIONS_INC
#define CONCESSIONS_INC
#include<iostream>
using namespace std;
class Concessions{
    protected:
    double concession_;
    public:
    Concessions(double value) ;//CCR
    virtual ~Concessions();//Destructor
    inline double getConcession() const {return concession_;}
    static bool UnitTestConcession();//For Unit Testing
};
#endif