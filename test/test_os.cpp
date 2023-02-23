#include <gtest/gtest.h>

#include <cstdint>

#include "impl/os_rng.h"

using rng::impl::OsRng;

TEST(Os, Random) {
    OsRng os;
    uint64_t a = os.get_uint64();
    uint64_t b = os.get_uint64();

    std::cout << a << " " << b << std::endl;

    EXPECT_NE(a, 0);
    EXPECT_NE(a, b);
}