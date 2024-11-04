#include <gtest/gtest.h>
#include "../include/lab1.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(removeVowels("GoogleTest groups the test results by test suites.") == "GglTst grps th tst rslts b tst sts.");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(removeVowels("Write your code in this editor and press Run.") == "Wrt r cd n ths dtr nd prss Rn.");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(removeVowels("Bella.") == "Bell.");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(removeVowels("Auaui pools.") == " pols.");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(removeVowels("Availability: Linux, Windows, Mac.") == "vlblt: Lnx, Wndws, Mc.");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
