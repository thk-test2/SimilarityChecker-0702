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

TEST(SimilarityChecker, LengthDouble) {
    SimilarityChecker sc{ "A" };

    double actual = sc.check("BB");

    EXPECT_EQ(0, actual);
}

TEST(SimilarityChecker, LengthDouble2) {
    SimilarityChecker sc{ "AA" };

    double actual = sc.check("BBBBB");

    EXPECT_EQ(0, actual);
}

TEST(SimilarityChecker, LengthDouble3) {
    SimilarityChecker sc{ "CCCAAAAA" };

    double actual = sc.check("ED");

    EXPECT_EQ(0, actual);
}

TEST(SimilarityChecker, LengthPartialScore1) {
    SimilarityChecker sc{ "AAABB" };

    int actual = sc.check("BAA");

    EXPECT_EQ(20, actual);
}

TEST(SimilarityChecker, LengthPartialScore2) {
    SimilarityChecker sc{ "AA" };

    int actual = sc.check("AAE");

    EXPECT_EQ(30, actual);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}
