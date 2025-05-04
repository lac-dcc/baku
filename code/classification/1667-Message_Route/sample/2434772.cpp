#include <bits/stdc++.h>
#include <bits/extc++.h>
#define double long double
#define int ll
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define ALL(X) X.begin(),X.end()
#define F(i,n)  FF(i,0,n)
#define F1(i,n)  FF(i,1,n+1)
#define FF(i,n,m) for(int i=(int)n;i<(int)m;++i)
//#pragma GCC optimize("Ofast,unroll-loops")
//#define mp make_pair
using namespace std;
template<typename T,typename P> bool remax(T& a, const P& b) {return b>a?a=b,1:0;}
template<typename T,typename P> bool remin(T& a, const P& b) {return b<a?a=b,1:0;}
inline ostream& operator << (ostream& os,__int128_t a){if(a==0) {return (os<<'0');}bool flag=0;if(a<0) {a=-a,flag=1;}string s;while(a){s+=a%10+'0';a/=10;}s+=flag?"-":"";reverse(ALL(s));return os<<s;}
inline istream& operator >>(istream& is,__int128_t& a){string s;cin>>s;a=0;for(auto c:s) a=a*__int128_t(10)+__int128_t(c-'0');return is;}
template<typename T,typename P> inline ostream& operator << (ostream& os,pair<T,P> a){os<<a.first<<" "<<a.second; return os;}
template<typename T,typename P> inline istream& operator >> (istream& is,pair<T,P> &a){is>>a.first>>a.second; return is;}
template<class T>
using rbtree =__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
using ll=long long;
using ull=unsigned long long;
using int128= __int128_t;
using uint128= __uint128_t;
using pii =pair<int,int>;
const double pi=acos(-1);
const int N=1E5+5;
const ll M=105;
const ll INF_64=0x3f3f3f3f3f3f3f3f;
const int INF_32=0x3f3f3f3f;
const int16_t INF_16=0x3f3f;
const int klog=20;
const int mod=1E9+7;//998244353
const double eps=1E-8;
void gen(){}
vector<int> g[N];
void sol(){
    int n,m;cin>>n>>m;
    F(i,m){
        pii t;cin>>t;
        g[t.first].pb(t.second);
        g[t.second].pb(t.first);
    }
    vector<int> fa(n+5,0);
    queue<int> q;q.push(1);
    fa[1]=-1;
    while(q.size()){
        int t=q.front();q.pop();
        for(auto x:g[t]){
            if(fa[x]==0){
                fa[x]=t;
                q.push(x);
                if(x==n){
                    vector<int> an;
                    int p=n;
                    while(p!=-1){
                        an.pb(p);
                        p=fa[p];
                    }
                    cout<<an.size()<<"\n";
                    reverse(ALL(an));
                    for(auto tt:an) cout<<tt<<" ";
                    return;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}
int32_t main(){
    #ifdef LOCAL
    //freopen("test_input.txt","r",stdin);
    //freopen(".out","w",stdout);
    #endif // LOCAL1
    IOS;
    int t=1;
    gen();
    //cin>>t;
    FF(i,1,t+1){
        //cout<<"Case #"<<i<<": ";
        sol();
    }
}
