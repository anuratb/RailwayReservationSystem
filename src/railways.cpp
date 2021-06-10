/**
 * @file railways.cpp
 * @author Anurat Bhattachjarya (19S10071)
 * @brief Railways Implementaion
 * @version 0.1
 * @date 2021-03-06
 *
 */
#include "../include/railways.h"
const vector<Station *> Railways::sStations = {Station::createStation("Mumbai"), Station::createStation("Delhi"), Station::createStation("Banglore"), Station::createStation("Kolkata"), Station::createStation("Chennai")};

const map<pair<string, string>, int> Railways::sDistStations =
    {
        make_pair(make_pair("Mumbai", "Delhi"), 1447),
        make_pair(make_pair("Mumbai", "Banglore"), 981),
        make_pair(make_pair("Mumbai", "Kolkata"), 2014),
        make_pair(make_pair("Mumbai", "Chennai"), 1338),
        make_pair(make_pair("Delhi", "Banglore"), 2150),
        make_pair(make_pair("Delhi", "Kolkata"), 1472),
        make_pair(make_pair("Delhi", "Chennai"), 2180),
        make_pair(make_pair("Banglore", "Kolkata"), 1871),
        make_pair(make_pair("Banglore", "Chennai"), 350),
        make_pair(make_pair("Kolkata", "Chennai"), 1659),
};

Railways::Railways() {}

const Railways &Railways::IndianRailWays()
{
    try
    {
        //Error Checking
        //Duplicate Station Checking
        set<string> chk;
        for (Station *itr : Railways::sStations)
        {
            if (chk.count(itr->GetName()) > 0)
            {
                throw Bad_Railways_dupSt();
            }
            chk.insert(itr->GetName());
        }
        //Distance Consistency Check
        set<pair<pair<string, string>, int>> dist;
        for(pair<pair<string,string>,int> itr:Railways::sDistStations)
        {
            if(dist.count(itr)>0)
            {
                throw Bad_Railways_dupDist();
            }
            else if(itr.first.first==itr.first.second)
            {
                throw Bad_Railways_dupDist();
            }
            else if(dist.count(make_pair(make_pair(itr.first.second,itr.first.first),itr.second))>0)
            {
                throw Bad_Railways_dupDist();
            }
            else
            {
                dist.insert(itr);
            }
        }
        //Return singleton
        static const Railways IndianRailways;
        return IndianRailways;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    
}

int Railways::GetDistance(const Station &frm, const Station &to) const
{
    try
    {
        if (Railways::sDistStations.count(make_pair(frm.GetName(), to.GetName())) > 0)
        {
            return Railways::sDistStations.find(make_pair(frm.GetName(), to.GetName()))->second;
        }
        else if((Railways::sDistStations.count(make_pair(to.GetName(), frm.GetName())) > 0))
        {
            return Railways::sDistStations.find(make_pair(to.GetName(), frm.GetName()))->second;
        }
        else if (to.GetName()==frm.GetName())
        {
            return 0;
        }
        else
        {
            throw Bad_Station();
        }
    }
    catch (const std::exception &e)
    {
        cout << e.what() << '\n';
    }
}
int Station::GetDistance(const Station &other) const
{
    return Railways::IndianRailWays().GetDistance(*this, other);
}
ostream &operator<<(ostream &os, const Railways &railways)
{
    os << "All Stations :";
    for (Station *st : Railways::sStations)
    {
        os << *st << " ";
    }
    os << endl;
    os << "Distance Matrix: " << endl;
    os << setw(15) << " ";
    for (Station *st : Railways::sStations)
    {
        os << setw(15) << *st;
    }
    os << endl;
    for (Station *st : Railways::sStations)
    {
        os << setw(12) << *st << " : ";
        for (Station *st2 : Railways::sStations)
        {
            os << setw(15) << Railways::IndianRailWays().GetDistance(*st, *st2);
        }
        os << endl;
    }
    return os;
}
bool Railways::UnitTestRailways()
{
    cout << "Doing Unit Testing for Railways Class...\n";
    bool flag = 1; //Assuming no error intiially
    vector<string> goldenContent = {"Mumbai", "Delhi", "Banglore", "Kolkata", "Chennai"};
    vector<string> actualContent;
    for (Station *st : Railways::sStations)
    {
        actualContent.push_back(st->GetName());
    }
    if (actualContent != goldenContent)
    {
        cout << "Error in Initializing List of Stations\n";
        flag = 0;
    }
    
    if ((Railways::IndianRailWays().GetDistance(*Station::createStation("Kolkata"),*Station::createStation("Mumbai"))!=2014)||(Railways::IndianRailWays().GetDistance(*Station::createStation("Mumbai"),*Station::createStation("Kolkata"))!=2014))
    {
        cout << "Error in Getting Distances between Stations\n";
        flag = 0;
    }
    
    
    //Testiong friend function for op stream
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/railways.txt", ios::in);
    ss << fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss << Railways::IndianRailWays();
    string op = ss.str();
    if (op != golden)
    {
        cout << "Expected:\n";
        cout << golden << endl;
        cout << "Output:\n";
        cout << op << endl;
        cout << "Error in output stream operator\n";
        flag = 0;
    }
    if (flag)
    {
        cout << "No Error Reported in Railways\n";
    }
    cout << endl;
    return flag;
}
