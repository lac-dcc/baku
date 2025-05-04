#include <bits/stdc++.h>
using namespace std;
 
 
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize ("unroll-loops")
 
 
typedef long long ll;
typedef long double ld;
typedef pair <ll,ll> pi;
typedef vector <ll> vi;
typedef complex <ld> P;
 
 
const ld PI =  3.1415926535897932384626433832795L;
const ld eps = 1e-9;
const ll mod = (1e9 + 7) * 2;
const ll inf = 1e15;
const ll N = 200500, M = 200500;
 
#define F first
#define S second
#define sqr(x) 1ll*x*x
#define PB push_back
#define PF push_front
#define rs resize
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)x.size()
#define X real()
#define Y imag()
 
ll n = 1,m,k,w,h,x,y,i,j,sum,prevs,cur;
ll a,b,c,d,q;
ll ans = 0;
vector <ll> vans;
ll l=0,r=1e18;
string s;
bool f=0,f1,f2;
int dd[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(20);
    //freopen("test_input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    vector <pair<ll,pi>> v(n);
    for(auto &e:v){
        cin>>e.S.F>>e.F>>e.S.S; //[b][a][p];
    }
    sort(all(v));
    set <pi> dp;
    dp.insert({0,0});
    for(int i=0;i<n;i++){
        auto t = dp.upper_bound({v[i].S.F,-1}); //[b][p]
        t--;
        x = v[i].S.S;
        if(t!=dp.begin()){
            x += (*t).S;
        }
        if(x>ans){
            ans = x;
            dp.insert({v[i].F,x});
        }
        //for(auto e:dp) cout<<e.F<<" "<<e.S<<"    ";
        //cout<<endl<<endl;
    }cout<<ans<<endl;
    return 0;
 
}
