/*! blackboardBold<Q> The set of rational numbers*/

#ifndef _BLACKBOARD_BOLD_Q_HPP_
#define _BLACKBOARD_BOLD_Q_HPP_

#include <iostream> // for iostream

namespace blackboardBold
{
    

/*! Greatest Common Denominator

*/
unsigned int gcd(unsigned int, unsigned int);// could be long or long long

/*! Least Common Multiple

*/
//unsigned int lcm(unsigned int, unsigned int);// could be long or long long

/*! The set of rational numbers*/
    class rat
    {
    private:

        bool isNegative;
        unsigned int numerator;
        unsigned int denominator;
        

        void reduce();

    public:
        /* Rule 0/3/5 stuff
            Im not sure if this stuff should be included yet. I am putting it here in comments as a reminder.
        */
        /*! Constructors (default)*/
        rat();

        /*! Constructors (non-default)*/

        /*! Constructor with Boolean, unsigned numerator and unsigned denominator*/
        rat(bool, unsigned int, unsigned int);

        /*! Constructor with signed numerator and unsigned denominator*/
        rat(int, unsigned int);
        
        /*! Constructor with unsigned numerator and signed denominator*/
        rat(unsigned int, int);
        
        /*! Constructor with signed numerator and signed denominator*/
        rat(int, int);

        /*! Constructor with single unsigned int.
            We assume the argument is the numerator and the denominator is 1.
        */
        rat(unsigned int);

        /*! Constructor with single signed int.
            We assume the argument is the numerator and the denominator is 1.
        */
        rat(int);

        /*! Conversion Operators*/
        template<typename realType> // float, double, ect.
        operator realType() const {
            realType result = static_cast<realType>(this->numerator)/static_cast<realType>(this->denominator);
            if (this->isNegative) {result *= (-1)};
            return result;
        }

        /*! Addition operator*/
        friend rat operator+(const rat&, const rat&);

        /*! Subtraction operator*/
        friend rat operator-(const rat&, const rat&);

        /*! Multiplication operator*/
        friend rat operator*(const rat&, const rat&);

        /*! Division operator*/
        friend rat operator/(const rat&, const rat&);

        /*! Equality operator*/
        friend bool operator==(const rat&, const rat&);

        /*! Inequality operator*/
        friend bool operator!=(const rat&, const rat&);

        /*! Less than operator*/
        friend bool operator<(const rat&, const rat&);

        /* I am commenting these out to see if the compiler can deduce them given only the first comparison operator*/
        ///*! Greater than operator*/
        //Is there a default: bool operator>(const Q&);

        ///*! Less than or equal to operator*/
        //Is there a default: bool operator<=(const Q&);

        ///*! Greater than or equal to operator*/
        //Is there a default: bool operator>=(const Q&);

        /*! Output Operations*/
        friend std::ostream& operator<<(std::ostream& , const rat&);

        };

inline const rat rat0 = rat(false, 0, 1);
inline const rat rat1 = rat(false, 1, 1);

}

#endif