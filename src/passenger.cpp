/**
 * @file passenger.cpp
 * @author Anurat Bhattachjarya (19S10071)
 * @brief PAssenger Implementation
 * @version 0.1
 * @date 2021-03-06
 *
 */
#include "../include/passenger.h"
//CR
Passenger::Passenger(string aadhar,const Date& dob, const Gender &gender, string mob, string firstName, string middleName, string lastName, string disablity_id , const Divyang *disabilityType ) : aadharNo_(aadhar), dob_(dob), gender_(gender), mob_(mob), disabilityID_(disablity_id), disabilityType_(disabilityType)
{
    Name N;
    N.firstName = firstName;
    N.middleName = middleName;
    N.lastName = lastName;
    this->name_ = N;
}
//CCR
Passenger::Passenger(const Passenger &other) : aadharNo_(other.aadharNo_), dob_(other.dob_), gender_(other.gender_), mob_(other.mob_), disabilityID_(other.disabilityID_), disabilityType_(other.disabilityType_)
{
    Name N;
    N.firstName = other.name_.firstName;
    N.middleName = other.name_.middleName;
    N.lastName = other.name_.lastName;
    this->name_ = N;
}
//CAO
Passenger &Passenger::operator=(const Passenger &other) //Blocked
{
    return *this;
}
ostream &operator<<(ostream &os, const Passenger &P)
{
    os << "Passenger Details:\n";
    os << "Name: " << P.name_.firstName << " " << P.name_.middleName << " " << P.name_.lastName << endl;
    os << "Aadhar Number: " << P.aadharNo_ << endl;
    os << "Date of Birth : " << P.dob_ << endl;
    os << "Gender: " << P.gender_.getName() << endl;
    os << "Mobile No.: " << P.mob_ << endl;
    os << "Disablity Id.: " << (P.disabilityID_ == "" ? "None" : P.disabilityID_) << endl;
    os << "Disability Type : " << (P.disabilityType_ == NULL ? "None" : P.disabilityType_->getDivyangName()) << endl;
    return os;
}
Passenger* Passenger::CreatePassenger(
    string aadhar,string dob,
     const Gender &gender,
    string mob, string firstName,
    string middleName, string lastName,
    string dsablity_id, const Divyang *disabilityType)
{
    try
    {
        if (aadhar.size() != 12)
        {
            throw Bad_Passenger_aadhar();
        }
        if (mob.size() != 10)
        {
            throw Bad_Passenger_mobile();
        }
        if (firstName.size() == 0 && lastName.size() == 0)
        {
            throw Bad_Passenger_name();
        }
        if (dsablity_id.size() > 0)
        {
            if (disabilityType == NULL)
            {
                throw Bad_Passenger_divyang("Divyang Type Not Present,but Id Present");
            }
        }
        if (disabilityType != NULL)
        {
            if (dsablity_id.size() == 0)
            {
                throw Bad_Passenger_divyang("Divyang Id not Present but ID present");
            }
        }
        Date Dob = Date::createDate(dob);
        return new Passenger(aadhar, Dob, gender, mob, firstName, middleName, lastName, dsablity_id, disabilityType);
         
    }catch (const exception& e)    
    {
        throw;      
    }
    
}
int Passenger::getAge() const
{
    time_t t = time(0);
    tm* now = localtime(&t);
    int  yr = now->tm_year+1900;    
    int age = yr - this->dob_.getYear();    
    if((dob_.getMonth()-1)>now->tm_mon)
    {
        age--;
    }
    else if((dob_.getMonth()-1)==now->tm_mon&&dob_.getDate()>now->tm_mday)
    {
        age--;
    }
    return age;
}

bool Passenger::UnitTestPassenger()
{
    cout<<"Doing Unit Testing for Passenger Class...\n";
    bool flag = 1; //intially assume no errors
    Passenger *P1;
    Passenger *P3;    
    Passenger *P5;    
    Passenger *P8;
    P5 = Passenger::CreatePassenger("415621478953", "6/6/1960", Gender::Female::Type(), "4512639876", "", "", "Satine");
    P1 = Passenger::CreatePassenger("123456781234", "1/2/1980", Gender::Male::Type(), "9433222222", "Anakin", "", "Skywalker", "1111", &Divyang::Ortho::Type());    
    P3 = Passenger::CreatePassenger("896412357412", "18/6/1970", Gender::Male::Type(), "9433821652", "Obi", "Vann", "Kenobi");
    P8 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485123654", "Jabba", "", "", "8451", &Divyang::Tb::Type());
    Passenger P9(*P1);
    Passenger P10 = *P1;
    Passenger* P11;
    stringstream ss;
    try
    {
        //BAD Aadhar
        P11 = Passenger::CreatePassenger("84125031012", "21/6/1940", Gender::Male::Type(), "7485123654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }

    try
    {
        //BAD phone
        P11 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "748512654", "", "", "Hutt", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }

    try
    {
        //BAD name
        P11 = Passenger::CreatePassenger("841250310123", "21/6/1940", Gender::Male::Type(), "7485126544", "", "", "", "8451", &Divyang::Tb::Type());
    }
    catch (const exception &e)
    {
        ss << e.what() << endl;
    }
    if(P1->aadharNo_!="123456781234")
    {
        cout<<"Error in initilizing Aadhar No., set as "<<P1->aadharNo_<<", should be set as 123456781234\n";
        flag = 0;
    }
    if(P1->disabilityType_->getDivyangName()!="Ortho")
    {
        cout<<"Error in initilizing Divyang Type, set as "<<P1->disabilityType_->getDivyangName()<<", should be set as Ortho\n";
        flag = 0;
    }
    if(!(P1->dob_==Date::createDate(1,2,1980)))
    {
        cout<<"Error in initilizing DOB, set as "<<P1->dob_<<", should be set as 1/February/1980\n";
        flag = 0;
    }
    if(P1->gender_.getName()!="Male")
    {
        cout<<"Error in initilizing Gender, set as "<<P1->gender_.getName()<<", should be set as Male\n";
        flag = 0;
    }
    if(P1->mob_!="9433222222")
    {
        cout<<"Error in initilizing Mobile No. , set as "<<P1->mob_<<", should be set as 9433222222\n";
        flag = 0;
    }
    if((P1->name_.firstName!="Anakin")||(P1->name_.lastName!="Skywalker"))
    {
        cout<<"Error in initilizing Name , set as "<<P1->name_.firstName<<" "<<P1->name_.middleName<<" "<<P1->name_.lastName<<", should be set as Anakin Skywalker\n";
        flag = 0;
    }
    //TEsting CCR
    
    if((P9.aadharNo_!="123456781234")||(P9.disabilityType_->getDivyangName()!="Ortho")||(!(P9.dob_==Date::createDate(1,2,1980)))||(P9.gender_.getName()!="Male")||(P9.mob_!="9433222222")||(P9.name_.firstName!="Anakin")||((P9.name_.lastName!="Skywalker")))
    {
        cout<<"Error in Copy Constructor\n";
        flag = 0;
    }
    //Testing CAO
    if((P10.aadharNo_!="123456781234")||(P10.disabilityType_->getDivyangName()!="Ortho")||(!(P10.dob_==Date::createDate(1,2,1980)))||(P10.gender_.getName()!="Male")||(P10.mob_!="9433222222")||(P10.name_.firstName!="Anakin")||((P10.name_.lastName!="Skywalker")))
    {
        cout<<"Error in Copy Assignment operator \n";
        flag = 0;
    }

    //Testing OP stream operator
    
    
    ss<<*P1;
    ss<<*P3;
    ss<<*P5;
    ss<<*P8;    
    string op = ss.str();
    ss = stringstream();
    ifstream fin("../outputs/unit_test_goldens/passenger.txt");
    ss<<fin.rdbuf();
    string golden = ss.str();
    if(op!=golden)
    {
        cout<<"Error in Passenger OP stream operator\n";
        cout<<"Expected:\n"<<golden<<endl;
        cout<<"Output:\n"<<op<<endl;
        flag = 0;
    }
    if(flag)
    {
        cout<<"No Errors reported for Passenger Class\n";
    }
    cout<<endl;
    return flag;
}
