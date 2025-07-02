#include <string>
#include <cstdlib>

using namespace std;

class SimilarityChecker {
public:
    SimilarityChecker() {}
    SimilarityChecker(string solution) : solution{ solution } {}

    int check(const string& input) {
        int solutionLength = solution.length();
        int inputLength = input.length();

        if (isDoubleLength(solutionLength, inputLength)) { return 0; }

        double score = calculateScore(solutionLength, inputLength);

        return score;
    }

    void setSolution(const string& input) {
        solution = input;
    }

private:
    string solution;

    double calculateScore(int solutionLength, int inputLength) {
        double gap = 0.0;
        double result = 0.0;
        if (solutionLength > inputLength) {
            gap = solutionLength - inputLength;
            result = (1 - gap / inputLength) * 60.0;
        }
        else {
            gap = inputLength - solutionLength;
            result = (1 - gap / solutionLength) * 60.0;
        }
        return result;
    }

    bool isDoubleLength(int solutionLength, int inputLength) {
        return (solutionLength >= inputLength * 2)
            || (inputLength >= solutionLength * 2);
    }
};
