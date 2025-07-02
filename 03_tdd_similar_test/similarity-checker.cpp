#include <string>
#include <cstdlib>

using namespace std;

class SimilarityChecker {
public:
    SimilarityChecker(string solution) : solution{ solution } {}

    int check(const string& input) {
        int sl = solution.length();
        int il = input.length();

        int gap = sl > il ? sl - il : il - sl;
        if (gap == 0) return 60;

        return 0;
    }

private:
    string solution;
};
