#include "catch.hpp"
#include "../bitops.h"

TEST_CASE("bit_flip") {
    int x = 2;
    // flip a few times
    REQUIRE(bit_flip(x, 3) == 6);
    REQUIRE(x == 6);

    REQUIRE(bit_flip(x, 3) == 2);
    REQUIRE(x == 2);

    REQUIRE(bit_flip(x, 3) == 6);
    REQUIRE(x == 6);

    // flip 0 to 1
    x = 0;
    REQUIRE(bit_flip(x, 1) == 1);
    REQUIRE(x == 1);

    // flip 1 to 0 again
    REQUIRE(bit_flip(x, 1) == 0);
    REQUIRE(x == 0);
}

TEST_CASE("is_bit_set") {
    REQUIRE(is_bit_set(0, 1) == false);
    REQUIRE(is_bit_set(1, 1) == true);

    REQUIRE(is_bit_set(0b00010000, 5) == true);
    REQUIRE(is_bit_set(0b00000010, 1) == false);
}

TEST_CASE("bit_set") {
    int x = 0;
    REQUIRE(is_bit_set(x, 1) == false);
    bit_set(x, 1);
    REQUIRE(is_bit_set(x, 1) == true);

    // make sure it doesn't flip and really just sets by setting again
    // and expecting no difference in output
    bit_set(x, 1);
    REQUIRE(is_bit_set(x, 1) == true);

    // now make sure the return value makes sense
    x     = 1;
    int y = bit_set(x, 2);
    REQUIRE(x == y);
}

TEST_CASE("bit_unset") {
    int x = 0b11;
    bit_unset(x, 1);
    REQUIRE(x == 0b10);

    bit_unset(x, 2);
    REQUIRE(x == 0b00);

    REQUIRE(x == 0);

    x = 0b10;
    bit_unset(x, 1);
    REQUIRE(x == 0b10);

    // test return value
    x     = 3;
    int y = bit_unset(x, 1);
    REQUIRE(x == y);
}

TEST_CASE("is_bitmask_set") {
    unsigned char i    = 0b00000000;
    unsigned char mask = 0b01010101;

    REQUIRE(is_bitmask_set(i, mask) == false);

    i = mask;

    REQUIRE(is_bitmask_set(i, mask) == true);

    i = 0b11111111;

    REQUIRE(is_bitmask_set(i, mask) == true);

    bit_unset(i, 1);

    REQUIRE(is_bitmask_set(i, mask) == false);

    i    = 0;
    mask = 0;

    REQUIRE(is_bitmask_set(i, mask) == true);
}


TEST_CASE("bit_set_mask") {
    unsigned char i    = 0;
    unsigned char mask = 0b11111111;

    bit_set_mask(i, mask);
    REQUIRE(is_bitmask_set(i, mask) == true);

    // make sure it doesn't flip
    bit_set_mask(i, mask);
    REQUIRE(is_bitmask_set(i, mask) == true);

    i    = 0b10101010;
    mask = 0b00000001;

    bit_set_mask(i, mask);
    REQUIRE(i == 0b10101011);

    // check return value
    i     = 0;
    mask  = 3;
    int y = bit_set(i, mask);
    REQUIRE(i == y);
}
