#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    string hh = time.substr(0,2);
    int hhVal = stoi(hh);
    bool isPM = (time[8] == 'P'); 
    if (hhVal == 12) {
        if (isPM) {   
            time[0] = '1';
            time[1] = '2';
        } else {      
            time[0] = '0';
            time[1] = '0';
        }
    } else {
        if (isPM) {   
            hhVal += 12;
            hh = to_string(hhVal);
            time[0] = hh[0];
            time[1] = hh[1];
        } else {
            // Do nothing
        }
    }
    cout << time.substr(0,8) << endl;
    return 0;
}
