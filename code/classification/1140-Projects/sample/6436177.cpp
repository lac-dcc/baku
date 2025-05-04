#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
struct Project {
    int start = 0;
    int end = 0;
    int reward = 0;
};
 
bool compareProjects (const Project &p1, const Project &p2) {
    return p1.end < p2.end;
}
 
void Projects_solution () {
    int n = 0;
    cin >> n;
 
    vector <Project> projects (n);
    for (int k = 0; k < n; k++) {
        cin >> projects[k].start >> projects[k].end >> projects[k].reward;
    }
 
    sort (projects.begin(), projects.end(), compareProjects);
 
    long long bestTotalReward = 0;
    map <long long, long long> dp;
    dp[0] = 0;
    for (const auto &project : projects) {
        auto it = dp.lower_bound(project.start);
            it--;
            long long totalReward = it->second + project.reward;
            bestTotalReward = max(bestTotalReward, totalReward);
        dp[project.end] = bestTotalReward;
    }
    cout << bestTotalReward;
}
 
int main() {
    Projects_solution();
    return 0;
}