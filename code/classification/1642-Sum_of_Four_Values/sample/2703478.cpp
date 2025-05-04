#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ull unsigned long long
#define int ll
#define rep(i, m, n) for (int i = m; i < n; i++)
#define rev(i, n, m) for(int i=n-1; i>=m; i--)
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define SET(n) cout << fixed << setprecision(n)
#define pii pair<int, int>
#define vi vector<int> 
#define vpii vector<pii> 
#define MOD 1000000007
#define INF 1e12 + 1
 
void Solve(){
    int n, x;
    cin>>n>>x;
    int a[n], sum=0;
    rep(i, 0, n){
        cin>>a[i];
        sum+=a[i];
    }
    if(n<4){
        cout<<"IMPOSSIBLE";
        return;
    }
    if(n==4){
        if(sum==x){
            cout<<"1 2 3 4";
            return;
        }
        else
            cout<<"IMPOSSIBLE";
        return;
    }
    vector<pair<int, pair<int, int>>> v;
    rep(i, 0, n-1){
        rep(j, i+1, n){
            v.pb({a[i]+a[j], {i+1, j+1}});
        }
    }
    sort(v.begin(), v.end());
    int j=v.size()-1, i=0;
    while(j>i){
        if(v[i].ff+v[j].ff==x){
            cout<<v[i].ss.ff<<" "<<v[i].ss.ss<<" "<<v[j].ss.ff<<" "<<v[j].ss.ss;
            return;
        }
        else if(v[i].ff+v[j].ff>x)
            j--;
        else 
            i++;
    }
    cout<<"IMPOSSIBLE";
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("C:/Computer programs/input.txt", "r", stdin);
    freopen("C:/Computer programs/output.txt", "w", stdout);
#endif
 
    int T = 1;
    //cin>>T;
    rep(i, 1, T+1)
    {
        //cout<<"Case "<<i<<" : ";
        Solve();
        cout << endl;
    }
 
#ifndef ONLINE_JUDGE
    cerr << "\nTime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
 
    return 0;
}