/**
 * @file station.cpp
 * @author Anurat Bhattachjarya (19S10071)
 * @brief Station Implementation
 * @version 0.1
 * @date 2021-03-06
 *
 */

#include "../include/station.h"
Station::Station(string name) : name_(name) {}
Station::Station(const Station &other) : name_(other.name_) {}
ostream &operator<<(ostream &os, const Station &st)
{
    os << st.name_;
    return os;
}
Station * Station::createStation(const string &name)
{
    try
    {
        if (name.size() == 0)
        {
            throw Bad_Station();
        }
        return new Station(name);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        throw;
    }
    
}
bool Station::UnitTestStation()
{
    cout << "Doing Unit Test for Station...\n";
    bool flag = 1; //flag = 1 for no error ,initially assuming no error
    Station s1("Kolkata");
    Station s2("Mumbai");
    if ((s1.GetName() != "Kolkata") || (s2.GetName() != "Mumbai"))
    {
        flag = 0;
        cout << "Error in Constructing Station with Valid name.\n";
    }
    if (s1.GetDistance(s2) !=2014)
    {
        flag = 0;
        cout << "Error in Initializing Distances or Error in GetDistance Function\n";
    }
    Station s3(s2);
    //Testing CCR
    if (s3.name_ != "Mumbai")
    {
        cout << "Error in Copy Constructor\n";
        flag = 0;
    }
    //Testing op stream operator
    stringstream ss;
    ifstream fin("../outputs/unit_test_goldens/station.txt");
    ss << fin.rdbuf();
    string golden = ss.str();
    ss = stringstream();
    ss << s1;
    string op = ss.str();
    if (op != golden)
    {
        cout << "Error in Station OP stream operatopr\n";
        cout << "Expected:\n"
             << golden << endl;
        cout << "Output:\n"
             << op << endl;
        flag = 0;
    }
    if (flag)
    {
        cout << "No Errors reported for Station class\n";
    }
    cout << endl;
    return flag;
}