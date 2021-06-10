#include "../include/bad_passenger.h"
Bad_Passenger::Bad_Passenger(string err_msg) : err_msg_(err_msg) {}
Bad_Passenger::~Bad_Passenger() {}

Bad_Passenger_name::Bad_Passenger_name() : Bad_Passenger("Invalid Passenger Name") {}
Bad_Passenger_name::~Bad_Passenger_name() {}

Bad_Passenger_age::Bad_Passenger_age() : Bad_Passenger("Invalid Passenger Age") {}
Bad_Passenger_age::~Bad_Passenger_age() {}

Bad_Passenger_aadhar::Bad_Passenger_aadhar() : Bad_Passenger("Invalid Passenger Aadhar") {}
Bad_Passenger_aadhar::~Bad_Passenger_aadhar() {}

Bad_Passenger_mobile::Bad_Passenger_mobile() : Bad_Passenger("Invalid Passenger Mobile") {}
Bad_Passenger_mobile::~Bad_Passenger_mobile() {}

Bad_Passenger_divyang::Bad_Passenger_divyang(string err_msg) : Bad_Passenger(err_msg) {}
Bad_Passenger_divyang::~Bad_Passenger_divyang() {}