#include <bits/stdc++.h>
#define ff cout<<"VALAMI"<<endl;
#define rr cout<<"VALAMI";
#define forn(n) for(int i = 0; i<n; ++i)
//#define int long long
 
using namespace std;
vector<vector<int>> T;
vector<int>dp (1e5+2,-1);
vector<bool> marvizsgalt(1e5+2,0);
int atmero = 0;
int atmeromely = 0;
 
int rek(int n, int mely)
{
    if(marvizsgalt[n]){return -1; }
    else
    {
        int k = 0;
        marvizsgalt[n] = 1;
        //cout<<"     "<<T[n].size()<<endl;
        for(int i = 0;i<T[n].size();++i)
        {
            k = max(k, rek(T[n][i],mely+1)+1);
        }
        if(atmeromely < mely+1){atmeromely = mely; atmero = n;}
        return k;
    }
}
 
void solve()
{
    int n,a,b;
    cin>>n;
    vector<int>  talami(0);
    forn(n+1){T.push_back(talami);}
    forn(n-1)
    {
        cin>>a>>b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    vector<bool> uresvizs(n+1,0);
    marvizsgalt = uresvizs;
    //cout<<"     "<<atmero<<endl;
    int f = rek(1,0);
    marvizsgalt = uresvizs;
    //cout<<atmero<<endl;
    f = rek(atmero,0);
 
    cout<<f<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
 
 
    /*
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
 
    */
 
 
}
