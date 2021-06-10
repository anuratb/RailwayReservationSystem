/**
 * @file station.h
 * @author Anurat Bhattcharya
 * @brief 
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include "bad_station.h"
using namespace std;
#ifndef STATION_INC
#define STATION_INC

class Station
{
    /**
     * @brief Station class
     * @param name_ : Name of the Station
     * 
     */
    string name_;
    Station(string name);                                       //Constructor

public:
    static Station * createStation(const string & name );
    Station(const Station &other);                              //CCTOR
    friend ostream &operator<<(ostream &os, const Station &st); //Output stream operator
    inline string GetName() const { return name_; }             //Returns the name of the station
    int GetDistance(const Station &other) const;             //Returns the Distance bettween current and other station
    friend bool operator==(const Station& A,const Station& B) {return A.name_==B.name_;}
    static bool UnitTestStation();
};
#endif