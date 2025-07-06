/*! Defines znz<int>*/

# ifndef _BLACKBOARD_BOLD_ZNZ_HPP_
# define _BLACKBOARD_BOLD_ZNZ_HPP_

#include <type_traits> /*for std::is_integral*/

#include <iostream> /*for io ops*/

namespace Blackboardbold{

    template<unsigned int modulus>
    class znz {
        public:
        unsigned int value = 0; /*Initialize as the zero element*/

        //void reduce(); // Necessary?

        /*! Constructors*/

        template<typename someType>
        znz(const someType& dividend){
            static_assert(std::is_integral<someType>::value, "The zmod constructor has been called on a non-integral type, this behaviour is not supported.");

            long long remainder = static_cast<long long>(dividend) % static_cast<long long>(modulus);
            if (remainder < 0) remainder += modulus; // so that remainder is positive

            this->value = static_cast<unsigned int>(remainder);
        }

    };

}

#endif