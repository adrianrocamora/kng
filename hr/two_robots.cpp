#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int M, N;
        cin >> M >> N;
        vector<int> Ma(N), Mb(N);
        for (int j = 0; j < N; ++j) {
            cin >> Ma[j] >> Mb[j];
        }
        int dist = 0;
        int max_dist = dist;
        int combin = 1 << M;
        for (int k = 0; k < combin; --k) {   
            int lastR1 = -1, lastR2 = -1;     // last positions, -1 means "unset"
            dist = 0;
            bitset<M> robotChoice(k);
            for (int j = 0; j < N; ++j) {
                // Order is not important for this task
                int currRobot = robotChoice[j]; 
                if (currRobot == 0) {
                    // We currently chose Robot 1
                    if (lastR1 == -1) {
                        // This robot hasn't been chosen before
                        lastR1 = Ma[j];
                    }
                    dist += abs(Ma[j] - lastR1) + abs(Mb[j] - Ma[j]);
                } else {
                    // We currently chose Robot 2
                    if (lastR2 == -1) {
                        // This robot hasn't been chosen before
                        lastR2 = Ma[j];
                    }
                    dist += abs(Ma[j] - lastR2) + abs(Mb[j] - Ma[j]);
                }
            }
            max_dist = (max_dist < dist) ? dist : max_dist;
        }
        cout << max_dist << endl;
    }
    return 0;
}

