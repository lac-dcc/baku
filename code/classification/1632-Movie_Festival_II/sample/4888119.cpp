#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define float long double
#define double long double
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(int i = a; i <= b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
//////*************Nitin1605***************//////
struct hmmmmm {
	bool operator()(const pair<int,int>& x, const pair<int,int>& y) const 
    { 
        if(x.first>y.first)return true;
        return x.second<y.second; 
    }
};  
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,k,x,y,ans=0,ct=0;
    cin >> n >> k;
    vector<pair<int,int>> a(n,{0,0});
    f(i,0,n-1)cin >> a[i].second >> a[i].first;
    sort(all(a));
    set<pair<int,int>,hmmmmm> lol;
    f(i,1,k)lol.insert({0,i});
    for(auto i:a)
    {
        auto it=lol.lower_bound({i.second,-1});
        if(it!=lol.end())
        {
            lol.erase(it);
            lol.insert({i.first,ans});
            ans++;
        }
    }
    cout << ans;
}
