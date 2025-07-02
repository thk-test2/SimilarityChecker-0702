#include <string>
#include <cstdlib>

using namespace std;

class SimilarityChecker {
public:
    SimilarityChecker(string solution) : solution{ solution } {}

    double check(const string& input) {
        int sl = solution.length();
        int il = input.length();

        if (sl >= il * 2 || il >= sl * 2) {
            return 0;
        }

        int gap = 0;
        double score = 0;

        if (sl > il) {
            gap = sl - il;
            score = (1 - gap / il) * 60.0;
        }
        else {
            gap = il - sl;
            score = (1 - gap / sl) * 60.0;
        }

        return score;
    }

private:
    string solution;
};
