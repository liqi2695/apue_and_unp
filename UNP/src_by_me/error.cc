#include "error.h"


void error_puts(std::string err, ...)
{
    std::cout << "ERROR:" << err << std::endl;
}