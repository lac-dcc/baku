#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans; vector<int>v1,v2;
void solve(int i, int n, int a[],int sum, vector<int>v){
    if(i >= n){
 
            for(auto x:v)sum+=x;
            v2.push_back(sum);
         return;
    }
    v.push_back(a[i]);
    solve(i+1, n, a,sum, v);
    v.pop_back();
    solve(i+1,n, a,sum, v);
}
int32_t main()
{
    int n , m; cin >> n >> m;
    int a[n+1];for(int i = 0; i < n; i++)cin >> a[i];
    int sum = 0;vector<int>v;
    map<int,int>mp; //mp[0]++;
    solve(0, n/2, a,sum, v);
    v1 = v2;
   // for(int i = 0; i < v2.size(); i++)mp[v2[i]]++;// cout << v2[i] << " ";cout << endl;
    v2.clear();
    solve(n/2, n, a,sum, v);
 
   //for(int i = 0; i < v1.size(); i++)cout << v1[i] << " ";cout <<endl;
   //for(int i = 0; i < v2.size(); i++)cout << v2[i] << " ";cout <<endl;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(auto x:v1){
        auto it1 = lower_bound(v2.begin(), v2.end(), m-x);
        auto it2 = upper_bound(v2.begin(), v2.end(), m-x);
        int a = it1 - v2.begin();
        int b = it2 - v2.begin(); ans += b-a;
    }cout << ans;
}
 
 
 
 
 
 
 
 
