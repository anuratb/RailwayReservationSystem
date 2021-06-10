/**
 * @file date.h
 * @author Anurat Bhattacharya (19CS10071)
 * @brief 
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <regex>
#include "bad_date.h"
using namespace std;
#ifndef DATE_INC
#define DATE_INC

class Date
{
    /**
     * @brief Private Members
     * @param d_: Date
     * @param m_ :Month
     * @param y_ :Year
     * @param w_ :Week index
     * 
     */
    int d_, m_, y_;
    static const vector<string> sDays;   //Day name
    static const vector<string> sMonths; //Month names
    static const vector<int> sMonthDays; //Days in each month
    Date(int d, int m, int y);           //CR

public:
    static bool isLeapYear(int year);
    friend int diffDate(const Date& d1,const Date& d2);//To get difference in dates
    friend bool withinOneYearAndOneDay(const Date& d1,const Date& d2);//To check if d2>d1 and withing 1 year
    static Date createDate(int d, int m, int y);//to get date month year
    inline int getYear() const {return y_;}
    inline int getMonth() const {return m_;}
    inline int getDate() const {return d_;}
    static Date createDate(const string & dt); //To get date in dd/mm/yyyy format
    Date(const Date &other);                                 //CCR
    Date &operator=(const Date &other);                      //CAO
    friend ostream &operator<<(ostream &os, const Date &dd); //Output Stream operator
    bool operator==(const Date &that);                       //Equality operator
    static bool UnitTestDate();                              //Unit Testing
};

#endif