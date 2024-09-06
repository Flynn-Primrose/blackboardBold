/*! blackboardBold<Q> The set of rational numbers*/

#ifndef _BLACKBOARD_BOLD_Q_HPP_
#define _BLACKBOARD_BOLD_Q_HPP_

namespace BlackboardBold
{
    /*! The set of rational numbers*/
    class Q
    {
    public:
        /*! Default constructor*/
        Q();
        /*! Copy constructor*/
        // 0/3/5 rule Q(const Q&);
        /*! Destructor*/
        // 0/3/5 rule ~Q();
        /*! Assignment operator*/
        // 0/3/5 rule Q& operator=(const Q&);
        /*! Addition operator*/
        Q operator+(const Q&);
        /*! Subtraction operator*/
        Q operator-(const Q&);
        /*! Multiplication operator*/
        Q operator*(const Q&);
        /*! Division operator*/
        Q operator/(const Q&);
        /*! Equality operator*/
        bool operator==(const Q&);
        /*! Inequality operator*/
        bool operator!=(const Q&);
        /*! Less than operator*/
        bool operator<(const Q&);
        /*! Greater than operator*/
        bool operator>(const Q&);
        /*! Less than or equal to operator*/
        bool operator<=(const Q&);
        /*! Greater than or equal to operator*/
        bool operator>=(const Q&);
    };
}

#endif