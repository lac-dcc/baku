#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
//#define f first
#define endl "\n"
#define se second
#define piii pair<int,pii>
#define id1 id<<1
#define id2 (id<<1)+1
#define MASK(i) (1<<i)
#define F3(i,a,b) for(int i=a;i<b;i++)
#define F0(i,a,b) for(int i=a;i<=b;i++)
#define f1(i,a,b) for(int i=a;i>=b;i--)
#define F2(i,a,b) for(int i=a;i<=b;i++,cout<<'\n')
#define TIME "\nTime elapsed : "<<(double)clock()/1000<<" ms"
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
const ll mod = 1e9;
const int maxn = 1e6 + 5;
const int maxs = 1e7;
 
ll n,m,v;
ll a[1001][1001];
 
int main()
{
    fast
    cin >> n >> m >> v;
    memset(a,0x3f,sizeof(a));
    ll tmp = a[2][3];
    for(int i = 1; i <= n; i++){
        a[i][i] = 0;
    }
 
    ll x,y,z;
 
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
 
        a[x][y] = a[y][x] = min(a[x][y],z);
    }
 
 
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                a[i][j] = a[j][i] = min(a[i][j],a[i][k] + a[k][j]);
            }
        }
    }
    for(int i = 1; i <= v; i++){
        ll k,l,ans;
        cin >> k >> l;
        if(a[k][l] != tmp){
            cout << a[k][l] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
 
}
