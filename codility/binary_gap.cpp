#include <iostream>
#include <string>

using namespace std;

int solution(int N)
{
    uint32_t num = static_cast<uint32_t>(N);
    int startIdx = -1;
    int maxGap = 0;
    for (int i = 0; i < 32; ++i) {
        int curr = ((num >> i) & 1);
        // First case
        if (startIdx == -1 && curr == 1) {
            startIdx = i;
            continue;
        } else if (curr == 1) {
            int currGap = i - startIdx - 1;
            maxGap = max({maxGap, currGap});
            startIdx = i;
        }
    }
    return maxGap;
}

int main()
{
    cout << "1: 0 == " << solution(1) << endl;
    cout << "3: 0 == " << solution(3) << endl;
    cout << "5: 1 == " << solution(5) << endl;
    cout << "7: 0 == " << solution(7) << endl;
    cout << "9: 2 == " << solution(9) << endl;
    cout << "529: 4 == " << solution(529) << endl;
}
