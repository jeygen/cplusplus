#include <cstdint> // using c library, some debate on how to implement
		   // as namespace can get complicated
#include <iostream>

/*
 * Using <cstdint> ensures exact size instead of using local arch. sizes
 * /

int main()
{
    // Use int32_t to guarantee that the variable will be a 32-bit integer
    int32_t x = -12345678;
    std::cout << x << std::endl;

    // Use uint8_t to guarantee that the variable will be an 8-bit unsigned integer
    uint8_t y = 255;
    std::cout << y << std::endl;

    return 0;
}

