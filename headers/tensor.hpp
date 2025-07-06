#ifndef _BLACKBOARD_BOLD_TENSOR_HPP_
#define _BLACKBOARD_BOLD_TENSOR_HPP_

#include <vector> // for std::vector

#define _TENSOR_PRODUCT_SYMBOL_ ^ /*! Symbol for tensor product. */
#define _TENSOR_DIVISION_SYMBOL_ % /*! Symbol for tensor division. */

#define _ELEMENTWISE_PRODUCT_SYMBOL_ * /*! Symbol for elementwise product. */
#define _ELEMENTWISE_DIVISION_SYMBOL_ / /*! Symbol for elementwise division. */

namespace BlackboardBold
{
    template <typename elType>
    class vctr: public std::vector<elType>{

        public:
        /* Constructors*/
        /* Member functions*/
            vctr invert();
            vctr transpose();

        /* Operator overloads */ 
            friend vctr operator+(vctr, vctr);
            friend vctr operator-(vctr, vctr);
            friend vctr operator _TENSOR_PRODUCT_SYMBOL_(vctr, vctr);
            friend vctr operator _TENSOR_DIVISION_SYMBOL_(vctr, vctr);
            friend vctr operator _ELEMENTWISE_PRODUCT_SYMBOL_(vctr, vctr);
            friend vctr operator _ELEMENTWISE_DIVISION_SYMBOL_(vctr, vctr);
    };

    template <typename elType>
    class mtrx{
        private:
            vctr<vctr<elType>> elements;
        public:
            friend mtrx operator+(mtrx, mtrx);
            friend mtrx operator-(mtrx, mtrx);
            friend mtrx operator _TENSOR_PRODUCT_SYMBOL_(vctr, vctr);
            friend mtrx operator _TENSOR_DIVISION_SYMBOL_(vctr, vctr);
            friend mtrx operator _ELEMENTWISE_PRODUCT_SYMBOL_(vctr, vctr);
            friend mtrx operator _ELEMENTWISE_DIVISION_SYMBOL_(vctr, vctr);
    };
}
#endif