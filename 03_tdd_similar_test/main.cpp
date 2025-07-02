#include "gmock/gmock.h"
#include "similarity-checker.cpp"

TEST(SimilarityChecker, LengthSame) {
    SimilarityChecker sc{ "ASD" };

    double actual = sc.check("DSA");

    EXPECT_EQ(60, actual);
}

TEST(SimilarityChecker, LengthSame2) {
    SimilarityChecker sc{ "ASDF" };

    double actual = sc.check("DSAB");

    EXPECT_EQ(60, actual);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}
