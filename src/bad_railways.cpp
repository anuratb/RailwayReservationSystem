#include "../include/bad_railways.h"
Bad_Railways::Bad_Railways(string err_msg) : err_msg_(err_msg) {}
Bad_Railways::~Bad_Railways() {}

Bad_Railways_dupSt::Bad_Railways_dupSt() : Bad_Railways("Duplicate Station"){}
Bad_Railways_dupSt::~Bad_Railways_dupSt() {}

Bad_Railways_dupDist::Bad_Railways_dupDist() : Bad_Railways("Duplicate Distance"){}
Bad_Railways_dupDist::~Bad_Railways_dupDist() {}