#include <iostream>
#include "test.h"
#include <sys/socket.h>
int main()
{
    int a = 3;
    int b = 7;
    std::cout << a << " | " << b << std::endl;
    swap(a,b);
    std::cout << a << " | " << b << std::endl;
    return 0;
}