#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

double distToBot(double c, double r, double botC, double botR) {
    return sqrt((c - botC) * (c - botC) + (r - botR) * (r - botR));
}

void findClosestDirtyCell(int& closeR, int& closeC, int botR, int botC, const vector<string>& board) {
    double closestDistToBot = 6.0; // Initializing to large value
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == botR && j == botC) { continue; } // Not necessary but good to have
            if (board[i][j] == 'd') {
                double currDistToBot = distToBot(i, j, botR, botC);
                if (currDistToBot < closestDistToBot) {
                    closeR = i;
                    closeC = j;
                    closestDistToBot = currDistToBot;
                }
            }
        }
    }
}

void next_move(int posr, int posc, vector <string> board) {
    // Look for the closest dirty cell
    if (board[posr][posc] == 'd') {
        cout << "CLEAN" << endl;
        return;
    } 
    int closeR, closeC;
    findClosestDirtyCell(closeR, closeC, posr, posc, board);
    int deltaR = closeR - posr;
    int deltaC = closeC - posc;
    if (deltaR < 0) {
        cout << "UP" << endl;
    } else if (deltaR > 0) {
        cout << "DOWN" << endl;
    } else if (deltaC < 0) {
        cout << "LEFT" << endl;
    } else if (deltaC > 0) {
        cout << "RIGHT" << endl;
    }
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}

