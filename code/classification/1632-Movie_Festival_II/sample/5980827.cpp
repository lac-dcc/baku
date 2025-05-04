#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll
#define endl "\n"
 
const int MOD = 998244353;
vector<vector<int>>Graph;
vector<int>Weights, Visited, Parent;
int c_end, c_start, val;
 
int32_t main(){
    int N, K;
    cin >> N >> K;
 
    vector<pair<int, int>>Times(N);
 
    for(int i = 0; i < N; i++){
        cin >> Times[i].second >> Times[i].first;
    }
 
    sort(begin(Times), end(Times));
 
    multiset<int>St;
    for(int i = 0; i < K; i++)St.insert(0);
 
    int answer = 0;
 
    // cout << "Got here" << endl;
 
    for(int i = 0; i < N; i++){
        auto itr = St.upper_bound(Times[i].second);
 
        if(itr != St.begin()){
            itr--;
            St.erase(St.find(*itr));
            St.insert(Times[i].first);
            answer++;
        }
    }
    cout << answer;
    return 0;
}   