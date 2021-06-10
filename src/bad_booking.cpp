#include "../include/bad_booking.h"

Bad_Booking::Bad_Booking(string err_msg): err_msg_(err_msg) {}
Bad_Booking::~Bad_Booking() {}

Bad_Booking_date::Bad_Booking_date() : Bad_Booking("Invalid Dates of Booking and Reservation") {}
Bad_Booking_date::~Bad_Booking_date() {}

Bad_Booking_st::Bad_Booking_st() : Bad_Booking("Invalid Station") {}
Bad_Booking_st::~Bad_Booking_st() {}

Bad_Booking_passenger::Bad_Booking_passenger() : Bad_Booking("Incompatible Passenger and Booking Category!") {}
Bad_Booking_passenger::~Bad_Booking_passenger() {}



