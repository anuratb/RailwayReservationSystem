#include "../include/BookingCategory.h"
BookingCategory::BookingCategory(string nme) : categoryName_(nme) {}
BookingCategory::~BookingCategory() {}
ostream& operator<<(ostream& os,const BookingCategory& bookCat)
{
    os<<bookCat.categoryName_;
    return os;
}