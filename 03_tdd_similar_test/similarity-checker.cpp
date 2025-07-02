#include <string>
#include <set>

using namespace std;

class SimilarityChecker {
public:
    SimilarityChecker() {}
    SimilarityChecker(string solution) : solution{ solution } {}

    int getLengthScore(const string& input) {
        int solutionLength = solution.length();
        int inputLength = input.length();

        if (isDoubleLength(solutionLength, inputLength)) { return 0; }

        double score = calculateLengthScore(solutionLength, inputLength);

        return score;
    }

    int getAlphabetScore(const string& input) {
        set<char> solutionSet;
        set<char> inputSet;

        for (auto ch : solution) {
            solutionSet.insert(ch);
        }

        for (auto ch : input) {
            inputSet.insert(ch);
        }
        
        if (solutionSet == inputSet) return 40;

        return 0;
    }

    void setSolution(const string& input) {
        solution = input;
    }

private:
    string solution;

    double calculateLengthScore(int solutionLength, int inputLength) {
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
