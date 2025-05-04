#include<bits/stdc++.h>
using ll = long long;
const int mod = 1E9 + 7;
const int INF = 1E9;
using namespace std;
 
void solve()
{   
    int n , sum;  cin >> n >> sum;
 
    map<int , int> m;
 
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
 
        if(m.count(sum - x)) {
            cout << i + 1 <<" " << m[sum - x] <<"\n";
            return;
        }
        m[x] = i + 1;
    }
 
    cout << "IMPOSSIBLE";
}
 
int main()
{
 
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
cout << fixed;cout << setprecision(10);
 
int t;
t = 1;
 
//std::cin >> t;
 
while(t--)
    solve();
    
return 0;
}