#include<bits/stdc++.h>
#include <cstdio>
#define endl "\n"
/*/*(last choice)*/ #define int long long
#define all(x) x.begin(), x.end()
#define ll long long
#define tsts int t; cin>>t; while(t--)
#define start cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
vector<int>v1,v2,v3,v4;
bool is;
void gtall(int i, int n, int ac=0)
{
    if(i==n)
    {
        (!is ? v3.push_back(ac) : v4.push_back(ac));
        return;
    }
    gtall(i+1,n,ac+(!is ? v1[i] : v2[i]));
    gtall(i+1,n,ac);
}
signed main()
{
    start
    //freopen("codeblocksinput.txt", "w", stdout);
    int n, x, ac=0;
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
        int xx;
        cin>>xx;
        if(i<n/2)
            v1.push_back(xx);
        else
            v2.push_back(xx);
    }
    gtall(0,n/2);
    is=1;
    gtall(0,n-n/2);
    sort(all(v4));
//    for(auto c:v3)
//        cout<<c<<' ';
//    cout<<endl;
//    for(auto c:v4)
//        cout<<c<<' ';
//    cout<<endl;
    for(int i=0; i<v3.size(); i++)
    {
        int j=lower_bound(all(v4),x-v3[i])-v4.begin();
        if(v4[j]!=x-v3[i])
            continue;
        int k=upper_bound(all(v4),x-v3[i])-v4.begin();
        ac+=k-j;
    }
    cout<<ac;
}
