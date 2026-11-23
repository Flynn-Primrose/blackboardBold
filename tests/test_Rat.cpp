#include "doctest.h"
#include "rat.hpp"

using namespace blackboardBold;

TEST_CASE("Rat normalizes to lowest terms") {
    CHECK(rat(2, 4) == rat(1, 2));
}