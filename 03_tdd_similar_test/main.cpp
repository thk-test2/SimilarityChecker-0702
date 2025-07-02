#include "gmock/gmock.h"
#include "similarity-checker.cpp"

class CheckerFixture : public testing::Test {
public:
    SimilarityChecker sc;
    void checkLength(const string& solution, const string& input, int score) {
        sc.setSolution(solution);

        EXPECT_EQ(score, sc.check(input));
    }
};

TEST_F(CheckerFixture, LengthSame) {
    checkLength("ASD", "DSA", 60);
    checkLength("ASDF", "DSAB", 60);
}

TEST_F(CheckerFixture, LengthDouble) {
    checkLength("A", "BB", 0);
    checkLength("AA", "BBBBB", 0);
    checkLength("CCCAAAAA", "ED", 0);
}

TEST_F(CheckerFixture, LengthPartialScore) {
    checkLength("AAABB", "BAA", 20);
    checkLength("AA", "AAE", 30);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}
