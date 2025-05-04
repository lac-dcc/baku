#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define lli long long int
#define pb push_back
#define in insert
#define mp make_pair
#define pii pair<int,int>
#define piil pair<lli,lli>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i>=b;i--)
#define b_pop(x)  __builtin_popcount(x)
#define b_clz(x) __builtin_clz(x)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie()
#define trav(a,x) for (auto& a: x)
#define deb(x) cout<<#x<<"="<<x<<"\n"//debugging
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int MX=(int)(2e5)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int arr[MX];
vector<int>graph[MX];
 
// Utility functions
void setPrec() { cout << fixed << setprecision(15); }
template<typename A>
A Max(A a,A b){
    return max(a,b);
}
template<typename A,typename... Args>
A Max(A a,A b,Args... args){
    return Max(Max(a,b),args...);
}
template<typename A>
void amin(A& a, A b){
    a=min(a,b);
}
template<typename A>
void amax(A& a, A b){
    a=max(a,b);
}
 
//GCD portion (without Euclids)
 
template<typename T>
 
T GCD(T a,T b){
    if(b==0)return a;
    else return GCD(b,a%b);
}
 
 
//adding a graph template
void ipgraph(int n,int m){
 
    int u,v;
    fo1(i,m){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
}
 
 
 
 
 
//problem solver
void solve(){
    
        int n,k;
        cin>>n>>k;
        vector<pii>vec;
        fo1(i,n){
            int u,v;
            cin>>u>>v;
            vec.pb(mp(v,u));
 
        }
        sort(all(vec));
            //probably we'll need some sort of binary search
        multiset<int>st;
        fo(i,k-1)st.in(0);
        st.in(vec[0].ff);
        int ans=1;
        int i=1;
        while(i<n){
 
            int strt=vec[i].ss;
            auto it=st.upper_bound(strt);
            if(it!=st.begin()){
 
                it=prev(it);
                st.erase(it);
                st.in(vec[i].ff);
                ans++;
            }
            i++;
        }
        cout<<ans<<"\n";
        // for(auto el:vec){
 
        //     cout<<el.ff<<" "<<el.ss<<"\n";
        // }
        // FORN(i,n-1,n-k)st.in()
   
}
 
 
int main(){ 
   
    // OJ;
 
    fast;
 
    int t;
    // cin>>t;
    t=1;
 
    while(t--){
        solve();
 
    }
    
    return 0;
}
 
