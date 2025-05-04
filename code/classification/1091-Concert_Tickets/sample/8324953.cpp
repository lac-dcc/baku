#include<bits/stdc++.h>
#define int long long
using namespace std;
bool isprime(int n)
{
    if (n==1||n==0)return 0;
    for (int i =2; i*i<=n; i++)
    {
        if (n%i==0)return 0;
    }
    return 1;
}
int LCM (int a, int b)
{
    return a/__gcd(a,b)*b;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >>n>>m;
    multiset <int>s;
    for  (int i =0;i<n;i++){
        int x;
        cin >>x;
        s.insert(x);
    }
    while (m--){
        int x;
        cin >>x;
        auto it =s.upper_bound(x);
        if (it==s.begin())cout <<-1 <<"\n";
        else {
            it--;
            cout <<*it <<"\n";s.erase(it);
        }
    }
 
}
