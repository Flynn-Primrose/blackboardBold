/*! Definitions for Q.hpp

*/

#include "Q.hpp"

#include <cmath> // for std::abs

using namespace BlackboardBold;


unsigned int BlackboardBold::gcd(unsigned int x, unsigned int y)
{
    unsigned int temp;
    while (y != 0)
    {
        temp = y;
        y = x % temp;
        x = temp;
    }
    return x;
}

void Q::reduce()
{
    unsigned int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

Q::Q(bool isNegative, unsigned int numerator, unsigned int denominator)
{
    this->isNegative = isNegative;
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

Q::Q(int numerator, unsigned int denominator)
{
    this->isNegative = (numerator < 0);
    this->numerator = std::abs(numerator);
    this->denominator = denominator;
    reduce();
}

Q::Q(unsigned int numerator, int denominator)
{
    this->isNegative = (denominator < 0);
    this->numerator = numerator;
    this->denominator = std::abs(denominator);
    reduce();
}

Q::Q(int numerator, int denominator)
{
    this->isNegative = (numerator < 0) ^ (denominator < 0);
    this->numerator = std::abs(numerator);
    this->denominator = std::abs(denominator);
    reduce();
}

/* Currently unused 
unsigned int BlackboardBold::lcm(unsigned int x, unsigned int y)
{
    return (x*y) / gcd(x, y);
}
 */

Q BlackboardBold::operator+(const Q& lhs, const Q& rhs)
{
    unsigned int new_denominator = lhs.denominator * rhs.denominator;
    unsigned int new_lhs_numerator = lhs.numerator * rhs.denominator;
    unsigned int new_rhs_numerator = rhs.numerator * lhs.denominator;
    unsigned int new_numerator;
    bool new_isNegative;
    switch (lhs.isNegative)
    {
        case true:
        {
            switch (rhs.isNegative)
            {
                case true:
                {
                    new_isNegative = true;
                    new_numerator = new_lhs_numerator + new_rhs_numerator;
                    break;
                }
                case false:
                {
                    (new_lhs_numerator > new_rhs_numerator) ? new_isNegative = true : new_isNegative = false;
                    (new_lhs_numerator > new_rhs_numerator) ? new_numerator = new_lhs_numerator - new_rhs_numerator : new_numerator = new_rhs_numerator - new_lhs_numerator;
                    break;
                }
            }
            break;
        }
        case false:
        {
            switch (rhs.isNegative)
            {
                case true:
                {
                    (new_lhs_numerator > new_rhs_numerator) ? new_isNegative = false : new_isNegative = true;
                    (new_lhs_numerator > new_rhs_numerator) ? new_numerator = new_lhs_numerator - new_rhs_numerator : new_numerator = new_rhs_numerator - new_lhs_numerator;
                    break;
                }
                case false:
                {
                    new_isNegative = false;
                    new_numerator = new_lhs_numerator + new_rhs_numerator;
                    break;
                }
            }
            break;
        }
    }
    return Q(new_isNegative, new_numerator, new_denominator);
}

Q BlackboardBold::operator-(const Q& lhs, const Q& rhs)
{
    return lhs + Q(!rhs.isNegative, rhs.numerator, rhs.denominator);
}

Q BlackboardBold::operator*(const Q& lhs, const Q& rhs)
{
    return Q(lhs.isNegative ^ rhs.isNegative, lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator);
}

Q BlackboardBold::operator/(const Q& lhs, const Q& rhs)
{
    return Q(lhs.isNegative ^ rhs.isNegative, lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator);//lhs * Q(rhs.isNegative, rhs.denominator, rhs.numerator) AKA invert and multiply
}


bool BlackboardBold::operator==(const Q& lhs, const Q& rhs)
{
    return (lhs.isNegative == rhs.isNegative) && (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
}


bool BlackboardBold::operator!=(const Q& lhs, const Q& rhs)
{
    return  !(lhs == rhs);
}


bool BlackboardBold::operator<(const Q& lhs, const Q& rhs)
{
    bool truth_value;

    switch(lhs.isNegative)
    {
        case true:
        {
            switch(rhs.isNegative)
            {
                case true:
                {
                    truth_value = (lhs.numerator * rhs.denominator) < (rhs.numerator * lhs.denominator);
                    break;
                }
                case false:
                {
                    truth_value = true;
                    break;
                }
            }
            break;
        }
        case false:
        {
            switch(rhs.isNegative)
            {
                case true:
                {
                    truth_value = false;
                    break;
                }
                case false:
                {
                    truth_value = (lhs.numerator * rhs.denominator) < (rhs.numerator * lhs.denominator);
                    break;
                }
            }
            break;
        }
    }

    return truth_value;
}   

