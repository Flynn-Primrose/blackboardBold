/*! Definitions for rat.hpp

*/

#include "Rat.hpp"

#include <cmath> // for std::abs

using namespace blackboardBold;


unsigned int blackboardBold::gcd(unsigned int x, unsigned int y)
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

void rat::reduce()
{
    unsigned int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

rat::rat()
{
    this->isNegative = false; /*isPositive is also false for the zero element.*/
    this->numerator = unsigned int (0);
    this->denominator = unsigned int (1);
    /*reduce(); is not necessary since it's already in lowest form */
}

rat::rat(bool isNegative, unsigned int numerator, unsigned int denominator)
{
    this->isNegative = isNegative;
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

rat::rat(int numerator, unsigned int denominator)
{
    this->isNegative = (numerator < 0);
    this->numerator = std::abs(numerator);
    this->denominator = denominator;
    reduce();
}

rat::rat(unsigned int numerator, int denominator)
{
    this->isNegative = (denominator < 0);
    this->numerator = numerator;
    this->denominator = std::abs(denominator);
    reduce();
}

rat::rat(int numerator, int denominator)
{
    this->isNegative = (numerator < 0) ^ (denominator < 0);
    this->numerator = std::abs(numerator);
    this->denominator = std::abs(denominator);
    reduce();
}

rat::rat(unsigned int numerator)
{
    this->isNegative = false;
    this->numerator = numerator;
    this->denominator = 1;
}

rat::rat(int numerator)
{
    this->isNegative = (numerator < 0);
    this->numerator = std::abs(numerator);
    this->denominator = 1;
}

rat blackboardBold::operator+(const rat& lhs, const rat& rhs)
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
    return rat(new_isNegative, new_numerator, new_denominator);
}

rat blackboardBold::operator-(const rat& lhs, const rat& rhs)
{
    return lhs + rat(!rhs.isNegative, rhs.numerator, rhs.denominator);
}

rat blackboardBold::operator*(const rat& lhs, const rat& rhs)
{
    return rat(lhs.isNegative ^ rhs.isNegative, lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator);
}

rat blackboardBold::operator/(const rat& lhs, const rat& rhs)
{
    return rat(lhs.isNegative ^ rhs.isNegative, lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator);//lhs * rat(rhs.isNegative, rhs.denominator, rhs.numerator) AKA invert and multiply
}


bool blackboardBold::operator==(const rat& lhs, const rat& rhs)
{
    return (lhs.isNegative == rhs.isNegative) && (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
}


bool blackboardBold::operator!=(const rat& lhs, const rat& rhs)
{
    return  !(lhs == rhs);
}


bool blackboardBold::operator<(const rat& lhs, const rat& rhs)
{
    return !(rhs-lhs).isNegative;
}   

std::ostream& blackboardBold::operator<<(std::ostream& os, const rat& q)
{
    if (q.isNegative)
    {
        os << '-';
    }
    os << q.numerator;
    if (q.denominator != 1)
    {
        os << '/' << q.denominator;
    }
    return os;
}

