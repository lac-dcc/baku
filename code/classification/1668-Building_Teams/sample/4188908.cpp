/* Madabhushi Priya Saaketh */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define trav(x,v)         for(auto &x:v)
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define ub                upper_bound
#define lb                lower_bound
#define pii               pair<int,int>
#define loop(i,a,b)       for(int i=a;i<b;++i)
#define rever(i,a,b)      for(int i=a;i>=b;--i)
#define reverall(x)       (x).begin(),(x).end(),greater<int>()
#define endl              '\n'
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<int,int> mpii;
const int M = 1e9+7;
const int N = 1e5+5;
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os  << p.first << " " << p.second<< endl; }
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_int_set; //less , less_equal , greater , greater_equal -> rule for insertion
typedef tree<string,null_type,less<string>,rb_tree_tag,tree_order_statistics_node_update>ordered_string_set; // find_by_order and order_of_key(x)->(count(elems)<x) (0-indexed)
bool bfs(int st,vi adj[],vi &team){
    queue<int> q;
        q.push(st);
        team[st] = 1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            int col = team[p];
            trav(ch,adj[p]){
                if(team[ch]==col){
                    return 0;
                }
                if(!team[ch]){
                    if(col==1){
                        team[ch] = 2;
                        q.push(ch);
                    }else{
                        team[ch] = 1;
                        q.push(ch);
                    }
                }
            }
        }
        return 1;
}
void saaketh(){
    int n,m;
    cin>>n>>m;
    vi adj[n];
    while(m--){
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi team(n,0);
    loop(i,0,n){
        if(!team[i]){
            if(!bfs(i,adj,team)){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for(auto &element:team){cout<<(element==0 ? 1:element)<<" ";}cout<<endl;
}
 
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    init();
#endif
int t=1;
// cin>>t;
loop(i,1,t+1){
    saaketh();
}
return 0;
}
