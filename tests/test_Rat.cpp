#include "doctest.h"
#include "rat.hpp"

#include <random>
#include <sstream>

using namespace blackboardBold;

TEST_CASE("Rat normalizes to lowest terms") {
    std::mt19937 rng(12345);  // fixed seed = reproducible
    std::uniform_int_distribution<int> dist(-1000, 1000);

    int x = dist(rng), y = dist(rng), z = dist(rng);

    CHECK(rat(x, y) == rat(z*x, z*y));
}

TEST_CASE("Rat addition") {
    std::mt19937 rng(12345);  // fixed seed = reproducible
    std::uniform_int_distribution<int> dist(-1000, 1000);

    int x = dist(rng), y=dist(rng), z = dist(rng);

    CHECK((rat(x, z) + rat(y, z)) == rat(x+y, z));
    CHECK((rat(x, y) + rat(x, z)) == rat(x*z+x*y, z*y));
}

TEST_CASE("Rat subtraction") {
    std::mt19937 rng(12345);  // fixed seed = reproducible
    std::uniform_int_distribution<int> dist(0, 1000); //non-negative for simplicity

    int x = dist(rng), y=dist(rng), z = dist(rng);

    CHECK((rat(x, z) - rat(y, z)) == rat(x-y, z));
    CHECK((rat(false, x, z) + rat(true, y, z)) == (rat(false, x, z) - rat(false, y, z)));
}

TEST_CASE("Rat multiplication") {
    std::mt19937 rng(12345);  // fixed seed = reproducible
    std::uniform_int_distribution<int> dist(-1000, 1000);

    int w = dist(rng), x = dist(rng), y=dist(rng), z = dist(rng);

    CHECK(rat(x, y)*rat(1, 1) == rat(x, y));
    CHECK(rat(w, x)*rat(y, z) == rat(w*y, x*z));
}

TEST_CASE("Rat division") {
    std::mt19937 rng(12345);  // fixed seed = reproducible
    std::uniform_int_distribution<int> dist(-1000, 1000); 

    int w = dist(rng), x = dist(rng), y=dist(rng), z = dist(rng);

    CHECK(rat(x, y)/rat(1,1) == rat(x, y));
    CHECK(rat(w, x)/rat(y, z) == rat(w, x)*rat(z, y));
}

TEST_CASE("Rat comparison") {
    std::mt19937 rng(12345);  // fixed seed = reproducible
    std::uniform_int_distribution<int> dist(0, 1000);//non-negative for simplicity

    int x = dist(rng), y=dist(rng), z = dist(rng);

    CHECK((rat(x, z) == rat(y, z)) == (x == y));
    CHECK((rat(x, z) < rat(y, z)) == (x < y));

}

TEST_CASE("Rat IO") {
    std::mt19937 rng(12345);  // fixed seed = reproducible
    std::uniform_int_distribution<int> dist(0, 1000);//non-negative for simplicity

    int x = dist(rng), y=dist(rng);

    std::ostringstream oss_pos, oss_neg;

    oss_pos << rat(false, x, y);
    oss_neg << rat(true, x, y);

    CHECK(oss_pos.str() == "x/y");
    CHECK(oss_neg.str() == "-x/y");

}