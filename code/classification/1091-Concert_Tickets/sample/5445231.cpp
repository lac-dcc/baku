#include <iostream>
#include<bits/stdc++.h>
#define ll long long 
#define x first 
#define ii pair <ll,ll>
#define y second 
using namespace std;
const int N = 200005; 
ll t[N] ,n , m , x , ans[N]; 
multiset<ll> s ; 
void Inp()
{
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> x ;
        s.insert(x) ; 
    } 
    for(int i = 1 ; i <= m ; i++) cin >> t[i] ; 
    s.insert(-1) ;
}
void Solve()
{
    for(int i = 1 ; i <= m ; i++)
    {
        auto j = s.upper_bound(t[i]) ;
        --j ;
        ans[i] = *j ; 
        s.erase(s.find(*j)) ; 
        s.insert(-1) ; 
 
    }
}
void Out() 
{
    for(int i = 1 ; i <= m ; i++) cout << ans[i]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    Inp();
    Solve();
    Out(); 
    return 0;
}   
