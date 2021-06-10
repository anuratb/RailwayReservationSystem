#include <iostream>
#include <iomanip>
/**
 * @file railways.h
 * @author Anurat Bhattacharya
 * @brief 
 * @version 0.1
 * @date 2021-03-06
 * 
 */
#include <string>
#include <vector>
#include<set>
#include<fstream>
#include <map>
#ifndef RAILWAY_INC
#define RAILWAY_INC
#include "station.h"
#include "bad_railways.h"
using namespace std;
class Railways
{
    Railways(); //TODO
    Railways(const Railways &other);
    Railways &operator=(const Railways &);
    ~Railways() {}

public:
    const static vector<Station*> sStations;
    const static map<pair<string,string>,int> sDistStations;
    static const Railways &IndianRailWays();
    int GetDistance(const Station &frm, const Station &to) const;
    friend ostream &operator<<(ostream &os, const Railways &railways); //OP Stream operator
    static bool UnitTestRailways();                                    //unit Testing
};
#endif