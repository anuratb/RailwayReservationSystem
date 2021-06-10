/**
 * @file date.cpp
 * @author Anurat Bhattacharya (19CS10071)
 * @brief Date Implementation
 * @version 0.1
 * @date 2021-03-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/date.h"
const vector<string> Date::sDays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const vector<string> Date::sMonths = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const vector<int> Date::sMonthDays = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};
Date::Date(int d, int m, int y) : d_(d), m_(m), y_(y) {}
Date::Date(const Date &other) : d_(other.d_), m_(other.m_), y_(other.y_) {}
Date &Date::operator=(const Date &other)
{
    this->d_ = other.d_;
    this->m_ = other.m_;
    this->y_ = other.y_;
    return *this;
}
ostream &operator<<(ostream &os, const Date &date)
{
    string year = to_string(date.y_);
    while (year.size() < 4)
        year.insert(year.begin(), '0');
    os << date.d_ << "/" << Date::sMonths[date.m_ - 1] << "/" << year;
    return os;
}
bool Date::operator==(const Date &that) { return d_ == that.d_ && m_ == that.m_ && y_ == that.y_; }
Date Date::createDate(int d, int m, int y)
{    
    try
    {
        if (d <= 0 || d > 31)
        {
            throw Bad_Date();
        }
        if (m <= 0 || m > 12)
            throw Bad_Date();
        if (y < 1900 || y > 2099)
            throw Bad_Date();
        if (m == 2 && d > 29)
        {
            throw Bad_Date();
        }
        
        else if (d == 29)
        {
            if ((y % 100 == 0 && (((y / 100) % 4) != 0)) || ((y % 4) != 0))
            {
                throw Bad_Date();
            }
        }
        if (m == 4 || m == 6 || m == 7 || m == 9 || m == 11)
        {
            if (d >= 31)
                throw Bad_Date();
        }
        if(y<1900||y>2099)
        {
            throw Bad_Date();
        }        
        Date D(d, m, y);
        return D;
    }
    catch (const exception &e)
    {
        //cout << e.what() << endl;
        throw;
    }
    
}
Date Date::createDate(const string &dt)
{
    //dd/mm/yyyy format
    try
    {       
        regex pat("([0-9])([0-9])*(/)([0-9])([0-9])*/[0-9]([0-9])*") ;
        if(!regex_match(dt,pat))
        {
            throw Bad_Date("Invalid Format of Date");
        }
        size_t i = dt.find_first_of("/");
        if(i==string::npos)
        {
            throw Bad_Date("Invalid Format of Date");
        }
        
        int date = atoi((dt.substr(0, i)).c_str()) ;
        size_t j = dt.find_first_of("/",i+1);
        if(j==string::npos)
        {
            throw Bad_Date("Invalid Format of date");
        }
        
        int month = atoi((dt.substr(i+1, j-i-1)).c_str()) ;
        int year = atoi((dt.substr(j+1,dt.size()-j-1)).c_str());
        return createDate(date,month,year);
    }
    catch (const exception &e)
    {
        //std::cerr << e.what() << '\n';
        throw;
    }
    
}
bool Date::isLeapYear(int y)
{
    return ((((y%100)!=0)&&((y%4)==0))||((y/4)%4==0));
}
int diffDate(const Date &A,const Date &B)
{
    if(A.y_>B.y_)   return -diffDate(B,A);
    int dmA = Date::sMonthDays[A.m_-1]-A.d_+1;//Days till end of month
    if(A.m_==1&&Date::isLeapYear(A.y_)) dmA++;
    for(int i=A.m_+1;i<12;i++)
    {
        dmA+=Date::sMonthDays[i];
        if(Date::isLeapYear(A.y_)&&i==1)  dmA++;
    }

    int dmB = Date::sMonthDays[B.m_-1]-B.d_+1;//Days till end of month
    if(B.m_==1&&Date::isLeapYear(B.y_)) dmB++;
    for(int i=B.m_+1;i<12;i++)
    {
        dmB+=Date::sMonthDays[i];
        if(Date::isLeapYear(B.y_)&&i==1)  dmB++;
    }
    int yr_diff=(B.y_-A.y_)*365 + ((B.y_-A.y_)/4);
    if((B.y_%4)<(A.y_%4))   yr_diff++;
    return dmA+yr_diff-dmB;


}


bool Date::UnitTestDate()
{
    Date date= Date::createDate("26/7/2018");
    Date d1(date);
    Date d2 = date;
        
    bool flag = 1;
    cout << "Running unit Tests For Date class...\n";
    if (date.d_ != 26)
    {
        cout << "Error in Date set as " << date.d_ << " should be 26";
        flag = 0;
    }
    if (date.m_ != 7)
    {
        cout << "Error in Month set as " << date.m_ << " should be 7\n";
        flag = 0;
    }
    if (date.y_ != 2018)
    {
        cout << "Error in Yesr set as " << date.y_ << " should be 2018\n";
        flag = 0;
    }
    if (!(date == Date(26, 7, 2018)))
    {
        cout << "Error in equality operator\n";
        flag = 0;
    }
    //Check the copy constructors
    if (!(date == d1))
    {
        cout << "Errror in copy constructor\n";
        flag = 0;
    }
    //Check CAO
    if (!(date == d2))
    {
        cout << "Errror in copy assignment operator\n";
        flag = 0;
    }
    //Testing Output Stream Operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/date.txt");
    ss << fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    //Test invalid Input
    try
    {
        Date d3 = Date::createDate(32,6,2019);
    }
    catch(const std::exception& e)
    {
        ss << e.what() << '\n';
    }
    try
    {
        Date d3 = Date::createDate("2/5//51/");
    }
    catch(const std::exception& e)
    {
        ss << e.what() << '\n';
    }
    ss << date;
    string op = ss.str();

    if (op != golden)
    {
        cout << "Error in output stream operator Date\n";
        cout << "Expected:\n";
        cout << golden << endl;
        cout << "Output:\n";
        cout << op << endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported in Date Class\n";
    }
    cout << endl;
    return flag;
}
