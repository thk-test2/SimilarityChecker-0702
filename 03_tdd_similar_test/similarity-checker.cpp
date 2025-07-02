#include <string>
#include <cstdlib>

using namespace std;

class SimilarityChecker {
public:
    SimilarityChecker(string solution) : solution{ solution } {}

    int check(const string& input) {
        int sl = solution.length();
        int il = input.length();

        if (isDoubleLength(sl, il)) { return 0; }

        double score = calculateScore(sl, il);

        return score;
    }

    double calculateScore(int sl, int il) {
        double gap = 0.0;
        double result = 0.0;
        if (sl > il) {
            gap = sl - il;
            result = (1 - gap / il) * 60.0;
        }
        else {
            gap = il - sl;
            result = (1 - gap / sl) * 60.0;
        }
        return result;
    }

    bool isDoubleLength(int sl, int il) {
        return sl >= il * 2 || il >= sl * 2;
    }

private:
    string solution;
};
