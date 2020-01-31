#include "catch.hpp"
#include "../bitops.h"

TEST_CASE("bitflip") {
    int x = 2;
    // flip a few times
    REQUIRE(bitflip(x, 3) == 6);
    REQUIRE(x == 6);

    REQUIRE(bitflip(x, 3) == 2);
    REQUIRE(x == 2);

    REQUIRE(bitflip(x, 3) == 6);
    REQUIRE(x == 6);

    // flip 0 to 1
    x = 0;
    REQUIRE(bitflip(x, 1) == 1);
    REQUIRE(x == 1);

    // flip 1 to 0 again
    REQUIRE(bitflip(x, 1) == 0);
    REQUIRE(x == 0);
}

TEST_CASE("is_bit_set") {
    REQUIRE(is_bit_set(0, 1) == false);
    REQUIRE(is_bit_set(1, 1) == true);

    REQUIRE(is_bit_set(0b00010000, 5) == true);
    REQUIRE(is_bit_set(0b00000010, 1) == false);
}

TEST_CASE("bitset") {
    int x = 0;
    REQUIRE(is_bit_set(x, 1) == false);
    bitset(x, 1);
    REQUIRE(is_bit_set(x, 1) == true);

    // make sure it doesn't flip and really just sets by setting again
    // and expecting no difference in output
    bitset(x, 1);
    REQUIRE(is_bit_set(x, 1) == true);

    // now make sure the return value makes sense
    x     = 1;
    int y = bitset(x, 2);
    REQUIRE(x == y);
}

TEST_CASE("bitunset") {
    int x = 0b11;
    bitunset(x, 1);
    REQUIRE(x == 0b10);

    bitunset(x, 2);
    REQUIRE(x == 0b00);

    REQUIRE(x == 0);

    x = 0b10;
    bitunset(x, 1);
    REQUIRE(x == 0b10);

    // test return value
    x     = 3;
    int y = bitunset(x, 1);
    REQUIRE(x == y);
}
