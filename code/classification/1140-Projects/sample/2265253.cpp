#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
 
using namespace std;
 
struct Project {
    int start, end, amount;
};
 
vector <Project> projects;
map <int, unsigned long long> money;
 
Project f(int x, int n) {
    int i, step;
    
    for (step = 1; step < n; step <<= 1) ;
    for (i = 0; step; step >>= 1) {
        if (i + step < n and projects[i + step].end < projects[x].start) {
            i += step;
        }
    }
    
    if (projects[i].end >= projects[x].start) {
        return {0, 0, 0};
    }
    return projects[i];
}
 
int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int start, end, amount;
        cin >> start >> end >> amount;
        projects.push_back({start, end, amount});
    }
    
    sort(projects.begin(), projects.end(), [](Project a, Project b){return a.end < b.end;});
    
    money[0] = 0;
    money[projects[0].end] = projects[0].amount;
    for (int i = 1; i < n; ++i) {
        money[projects[i].end] = max(money[projects[i-1].end], money[f(i, n).end] + projects[i].amount);
    }
    
    cout << money[projects[n - 1].end] << '\n';
    return 0;
}