///Never gonna give you up.
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
using namespace std;
using namespace __gnu_pbds;
template<class x>
using ordered_set = tree<x, null_type,less<x>, rb_tree_tag,tree_order_statistics_node_update>;
const ll mod=(ll)1e9+7;
const ll mod1=998244353;
///the defines :)
//#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
#define ent(arr) for(int i=0;i<arr.size();i++)cin>>arr[i];
#define all(arr) arr.begin(),arr.end()
#define allr(arr) arr.rbegin(),arr.rend()
#define sz size()
#define int long long
vi split(vi &arr)
{
    int n=arr.sz;
    vi rtr;
    for(int i=0; i<(1ll<<n); i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            if((1ll<<j)&i)
                sum+=arr[j];
        }
        rtr.push_back(sum);
    }
    return rtr;
}
void preprocess() {}
void solve()
{
    int n,x;
    cin>>n>>x;
    vi arr1;
    vi arr2;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(i<=(n/2))
            arr1.push_back(x);
        else
            arr2.push_back(x);
    }
    int ans=0;
    vi lol=split(arr1);
    vi lol1=split(arr2);
    sort(all(lol1));
    sort(all(lol));
    for(int i=0;i<lol.sz;i++)
    {
        if(lol[i]>x)break;
        int e=lower_bound(all(lol1),x-lol[i])-lol1.begin();
        int e1=upper_bound(all(lol1),x-lol[i])-lol1.begin();
        e1--;
        if(e1==-1||lol1[e1]!=(x-lol[i]))continue;
        ans+=(e1-e+1);
    }
    cout<<ans<<endl;
}
signed main()
{
    // freopen("div7.in","r",stdin);
    //freopen("div7.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preprocess();
    //bla();
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}
