#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start_time;
    int duration;
    int end_time;
    Workshop() : start_time(0), duration(0), end_time(0) {}
    Workshop(int in_start_time, int in_duration) : 
        start_time(in_start_time), duration(in_duration), end_time(start_time + duration) {}
    struct GreaterByEndtime {
        bool operator()(const Workshop& lhs, const Workshop& rhs) {
            return lhs.end_time > rhs.end_time;
        }
    };
    struct LessByEndtime {
        bool operator()(const Workshop& lhs, const Workshop& rhs) {
            return lhs.end_time < rhs.end_time;
        }
    };
};

struct Available_Workshops {
    int N;
    Workshop *workshops;
    Available_Workshops() : N(0), workshops(nullptr) { }
    Available_Workshops(int in_N, int in_start_time[], int in_duration[]) { 
        N = in_N;
        workshops = new Workshop[N];
        for (int i = 0; i < N; ++i) {
            workshops[i].start_time = in_start_time[i];
            workshops[i].duration = in_duration[i];
            workshops[i].end_time = in_start_time[i] + in_duration[i];
        }
    }
    ~Available_Workshops() {
        delete[] workshops;
    }
};

Available_Workshops* initialize(int start_time[], int duration[], int N) {
    Available_Workshops *res = new Available_Workshops(N, start_time, duration);
    return  res;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
    // Sort by end_time then go by start_time    
    vector<Workshop> v_ws;
    for (int i = 0; i < ptr->N; i++) {
        v_ws.push_back(ptr->workshops[i]);
    }
    sort(v_ws.begin(), v_ws.end(), Workshop::LessByEndtime());
    if (v_ws.empty()) { return 0; }
    Workshop prev = v_ws[0];
    int count = 1;
    for (int i = 1; i < v_ws.size(); i++) {
        Workshop tmp = v_ws[i];
        if (prev.end_time <= tmp.start_time) {
            count++;
            prev.start_time = tmp.start_time;
            prev.duration = tmp.duration;
            prev.end_time = tmp.end_time;
        }
    }
    //priority_queue<Workshop, vector<Workshop>, Workshop::GreaterByEndtime> p_ws(v_ws.begin(), v_ws.end());
    //if (p_ws.empty()) { return 0; }
    //Workshop prev = p_ws.top();
    //p_ws.pop();
    //int count = 1;
    //while (!p_ws.empty()) {
        //Workshop tmp = p_ws.top();
        //p_ws.pop();
        //if (prev.end_time <= tmp.start_time) {
            //count++;
            //prev.start_time = tmp.start_time;
            //prev.duration = tmp.duration;
            //prev.end_time = tmp.end_time;
        //}
    //}
    return count;
}
int main()
{
    int n;
    cin>>n;
    int start_time[n],duration[n];
    for(int i=0;i<n;i++)
    {
        cin>>start_time[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>duration[i];
    }
    Available_Workshops * ptr;
    ptr=initialize(start_time,duration,n);
    cout << "N: " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << ptr->workshops[i].start_time << " " << ptr->workshops[i].duration << " " << ptr->workshops[i].end_time << endl;
    }
    cout<<CalculateMaxWorkshops(ptr)<<endl;
    delete ptr;
    return 0;
}
