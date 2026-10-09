#include "hypotenuse.h"
#include "random_hypotenuse.h"
#include <gtest/gtest.h>
#include <iostream>
#include <type_traits>

TEST(Hypotenuse, Int) {
    EXPECT_EQ((Normal::hypotenuse<int, int>(3, 4)), 5);
    EXPECT_EQ((Normal::hypotenuse<int, int>(0, 0)), 0);
    EXPECT_EQ((Normal::hypotenuse<int, int>(-3, 4)), 5);
    EXPECT_EQ((Normal::hypotenuse<int, int>(1, 1)), 1);
    EXPECT_EQ((Normal::hypotenuse<int, int>(30000, 40000)), 50000);
}

TEST(Hypotenuse, InputAndOutputTypes) {
    static_assert(std::is_same_v<decltype(Normal::hypotenuse<int, double>(1, 1)), double>);
    static_assert(std::is_same_v<decltype(Random::hypotenuse<double, int>(3, 4)), int>);
    EXPECT_DOUBLE_EQ((Normal::hypotenuse<double, double>(1.5, 2.0)), 2.5);
    EXPECT_NEAR((Normal::hypotenuse<int, double>(1, 1)), std::sqrt(2.0), 1e-12);
    EXPECT_EQ((Normal::hypotenuse<double, int>(1.5, 2.0)), 2);
}

TEST(Hypotenuse, Random) {
    for (int i = 0; i < 100; ++i) {
        int result = Random::hypotenuse<double, int>(3.0, 4.0);
        EXPECT_GE(result, 5);
        EXPECT_LE(result, 15);
        double floating = Random::hypotenuse<int, double>(3, 4);
        EXPECT_TRUE(floating == 5.0 || (floating >= 6.0 && floating <= 15.0));
    }
}

// Run these deliberately failing tests with --gtest_also_run_disabled_tests.
TEST(DISABLED_FailureDemo, ExpectContinues) {
    EXPECT_EQ((Normal::hypotenuse<int, int>(3, 4)), 6);
    std::cout << "AFTER EXPECT: execution continues\n";
    EXPECT_EQ((Normal::hypotenuse<int, int>(5, 12)), 14);
}

TEST(DISABLED_FailureDemo, AssertStops) {
    ASSERT_EQ((Normal::hypotenuse<int, int>(3, 4)), 6);
    std::cout << "AFTER ASSERT: this line must not appear\n";
    EXPECT_EQ((Normal::hypotenuse<int, int>(5, 12)), 14);
}
