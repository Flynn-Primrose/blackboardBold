/*!
Definitions for gcd.hpp
*/

#include "gcd.hpp"

using namespace blackboardBold;

long long blackboardBold::gcd(long long x, long long y)
{
    long long temp;
    while (y != 0)
    {
        temp = y;
        y = x % temp;
        x = temp;
    }
    return x;
}