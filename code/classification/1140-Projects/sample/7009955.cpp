#include<iostream>
#include<vector>
#include<algorithm>
 
#define pii pair< pair<int, int> , int>
 
using namespace std;
 
bool myComp (pii a, pii b) {
    return (a.first.second <= b.first.second);
}
 
int findLastNonOverlap(vector< pii > & projects, int l, int r, int start) {
    int answer = l-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(projects[mid].first.second >= start) {
            r = mid -1;
        }
        else {
            answer = mid;
            l = mid+1;
        }
    }
    return answer;
}
 
int main () {
    int n;
    cin >> n;
 
    vector< pii > projects;
 
    for(int i=0; i<n; i++) {
        int a, b, r;
        cin >> a;
        cin >> b;
        cin >> r;
        pair<int, int> times(a, b);
        pii proj(times, r);
        projects.push_back(proj);
    }
    sort(projects.begin(), projects.end(), myComp);
 
    vector<long long> dp(n, 0);
    dp[0] = projects[0].second;
 
    for(int i=1; i<n; i++) {
        int prev = findLastNonOverlap(projects, 0, i-1, projects[i].first.first);
        if(prev >= 0)
            dp[i] = max(dp[i-1], projects[i].second + dp[prev]);
        else
            dp[i] = max(dp[i-1], (long long)projects[i].second);
    }
 
    cout << dp[n-1] << '\n';
}
