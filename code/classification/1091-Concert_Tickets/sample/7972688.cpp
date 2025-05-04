#include "bits/stdc++.h"
#define int long long
#define double long double
#define TxtIO  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
const int mod=1e9+7;
const int inf=1e18;
#define vi vector<int>
#define pii pair<int,int>
#define all(p) p.begin(),p.end()
#define fri(n) for(int i=0;i<n;i++)
#define fra(a) for(auto i:a)
#define fro(x,y,n) for(int i=x;i<y;i++)
using namespace std;
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n,m,x;
    cin>>n>>m;
    vi b(m);
    multiset<int>s;
    fri(n) cin>>x,s.insert(x);
    fri(n) cin>>b[i];
    int i=0;
    for(int j=0;j<m;j++)
    {
        auto it=s.upper_bound(b[j]);
        if(it==s.begin()) cout<<-1<<endl;
        else
        {
            cout<<(*(--it))<<endl;
            s.erase(it);
        }
    }
    return 0;
}
