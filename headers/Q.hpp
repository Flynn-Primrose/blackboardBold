/*! blackboardBold<Q> The set of rational numbers*/

#ifndef _BLACKBOARD_BOLD_Q_HPP_
#define _BLACKBOARD_BOLD_Q_HPP_

#include <iostream> // for iostream
namespace BlackboardBold
{
    

/*! Greatest Common Denominator

*/
unsigned int gcd(unsigned int, unsigned int);// could be long or long long

/*! Least Common Multiple

*/
unsigned int lcm(unsigned int, unsigned int);// could be long or long long

/*! The set of rational numbers*/
    class Q
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
        ///*! Default constructor*/
        //Q();

        ///*! Copy constructor*/
        //Q(const Q&);

        ///*! Destructor*/
        //~Q();

        ///*! Assignment operator*/
        //Q& operator=(const Q&);

        /*! Constructors (non-default)*/

        /*! Constructor with Boolean, unsigned numerator and unsigned denominator*/
        Q(bool, unsigned int, unsigned int);

        /*! Constructor with signed numerator and unsigned denominator*/
        Q(int, unsigned int);
        
        /*! Constructor with unsigned numerator and signed denominator*/
        Q(unsigned int, int);
        
        /*! Constructor with signed numerator and signed denominator*/
        Q(int, int);

        /*! Constructor with single unsigned int.
            We assume the argument is the numerator and the denominator is 1.
        */
        Q(unsigned int);

        /*! Constructor with single signed int.
            We assume the argument is the numerator and the denominator is 1.
        */
        Q(int);

        /*! Addition operator*/
        friend Q operator+(const BlackboardBold::Q&, const BlackboardBold::Q&);

        /*! Subtraction operator*/
        friend Q operator-(const BlackboardBold::Q&, const BlackboardBold::Q&);

        /*! Multiplication operator*/
        friend Q operator*(const BlackboardBold::Q&, const BlackboardBold::Q&);

        /*! Division operator*/
        friend Q operator/(const BlackboardBold::Q&, const BlackboardBold::Q&);

        /*! Equality operator*/
        friend bool operator==(const BlackboardBold::Q&, const BlackboardBold::Q&);

        /*! Inequality operator*/
        friend bool operator!=(const BlackboardBold::Q&, const BlackboardBold::Q&);

        /*! Less than operator*/
        friend bool operator<(const BlackboardBold::Q&, const BlackboardBold::Q&);

        /* I am commenting these out to see if the compiler can deduce them given only the first comparison operator*/
        ///*! Greater than operator*/
        //Is there a default: bool operator>(const Q&);

        ///*! Less than or equal to operator*/
        //Is there a default: bool operator<=(const Q&);

        ///*! Greater than or equal to operator*/
        //Is there a default: bool operator>=(const Q&);

        /* IO Operators*/
        /*! Output operator*/
        /* friend std::ostream& operator<<(std::ostream& , const Q&); */

        friend std::ostream& operator<<(std::ostream&, const Q&);

        };

inline const Q Q0 = Q(false, 0, 1);
inline const Q Q1 = Q(false, 1, 1);

}

#endif