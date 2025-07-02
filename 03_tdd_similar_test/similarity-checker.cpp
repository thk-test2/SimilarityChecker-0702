#include <string>

using namespace std;

class SimilarityChecker {
public:
    SimilarityChecker(string solution) : solution{ solution } {}

    int check(const string& input) {
        if (input.length() == solution.length()) {
            return 60;
        }
        return 0;
    }

private:
    string solution;
};
