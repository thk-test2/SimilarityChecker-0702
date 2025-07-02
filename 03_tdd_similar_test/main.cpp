#include "gmock/gmock.h"
#include "similarity-checker.cpp"

class CheckerFixture : public testing::Test {
public:
    SimilarityChecker sc;
    void checkLengthScore(const string& solution, const string& input, int score) {
        sc.setSolution(solution);

        EXPECT_EQ(score, sc.getLengthScore(input));
    }
};

TEST_F(CheckerFixture, LengthSame) {
    checkLengthScore("ASD", "DSA", 60);
    checkLengthScore("ASDF", "DSAB", 60);
}

TEST_F(CheckerFixture, LengthDouble) {
    checkLengthScore("A", "BB", 0);
    checkLengthScore("AA", "BBBBB", 0);
    checkLengthScore("CCCAAAAA", "ED", 0);
}

TEST_F(CheckerFixture, LengthPartialScore) {
    checkLengthScore("AAABB", "BAA", 20);
    checkLengthScore("AA", "AAE", 30);
}

TEST_F(CheckerFixture, SameAlphabets) {
    sc.setSolution("ASD");
    int actual = sc.getAlphabetScore("DSA");
    EXPECT_EQ(40, actual);
}

TEST_F(CheckerFixture, SameAlphabets2) {
    sc.setSolution("AAABB");
    int actual = sc.getAlphabetScore("BA");
    EXPECT_EQ(40, actual);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}
