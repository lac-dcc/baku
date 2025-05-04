#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define INF 1000000007
 
void test_case(){
    int n,x,y;
    cin >> n;
    vector<pair<int,int>> p;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        p.push_back({x,1});
        p.push_back({y,0});
    }
    sort(p.begin(),p.end());
    int curr = 0, ans = 0, m = p.size();
    for(int i = 0; i < m; i++){
        if(p[i].second == 1)
            curr++;
        else
            curr--;
        ans = max(ans,curr);
    }
    cout << ans << endl;
    return;
} 
 
int main() {
    int t;
    t = 1;
    while(t--)
        test_case();
    return 0;
}
     
