/*! Defines znz<int>*/

# ifndef _BLACKBOARD_BOLD_ZNZ_HPP_
# define _BLACKBOARD_BOLD_ZNZ_HPP_

#include <type_traits> /*for std::is_integral*/

#include <iostream> /*for io ops*/

namespace blackboardBold{

    template<unsigned int modulus>
    class znz {
        static_assert(modulus > 0, "Modulus must be greater than zero.")

        public:
        unsigned int value; 

        //void reduce(); // Necessary?

        /*! Constructors*/

        znz() : value(0) {} /*By default, initialize as the zero element*/

        template<typename someType>
        znz(const someType& dividend){
            static_assert(std::is_integral<someType>::value, "The zmod constructor has been called on a non-integral type, this behaviour is not supported.");

            long long remainder = static_cast<long long>(dividend) % static_cast<long long>(modulus);
            if (remainder < 0) remainder += modulus; // so that remainder is positive

            this->value = static_cast<unsigned int>(remainder);
        }

        /*! Addition operator*/
        friend znz operator+(const znz& lhs, const znz& rhs){
            return znz(lhs.value + rhs.value);
        }

        /*! Subtraction operator*/
        friend znz operator-(const znz& lhs, const znz& rhs){
            return znz(lhs.value - rhs.value);
        }

        /*! Multiplication operator*/
        friend znz operator*(const znz& lhs, const znz& rhs){
            return znz(lhs.value * rhs.value);
        }

        /*! Division operator*/
        friend znz operator/(const znz& lhs, const znz& rhs){
            /*Only possible if rhs has an inverse*/
        }

        /*! Equality operator*/
        friend bool operator==(const znz& lhs, const znz& rhs){
            return (lhs.value == rhs.value);
        }

        /*! Inequality operator*/
        friend bool operator!=(const znz& lhs, const znz& rhs){
            return (lhs.value != rhs.value);
        }

        /*! Less than operator*/
        friend bool operator<(const znz& lhs, const znz& rhs){
            return (lhs.value < rhs.value);
        }

        /*! Output Operations*/
        friend std::ostream& operator<<(std::ostream& os, const znz& z){
            os << z.value << " (mod " << modulus << ')';
            return os;
        }

    };

}

#endif