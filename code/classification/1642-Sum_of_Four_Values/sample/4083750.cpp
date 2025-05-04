#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).end(), (a).begin()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define error(args...) { string _s = #args;	replace(_s.begin(), _s.end(), ',', ' ');	stringstream _ss(_s);	istream_iterator<string> _it(_ss);	err(_it, args); }
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vstr;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const int INF = 1000000000;
const int MOD = 1000000007;
const double PI = acos(-1);
 
// s.find_by_order(i) = i-th element in the set (0-indexing)
// s.order_of_key(elem) = #items: {item<elem}
template<class T>
using ordered_set = tree<T,null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_multiset = tree<T,null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
void solve(){
    int n,x;
    cin>>n>>x;
    vii A(n);
    rep(i,0,n){
        cin>>A[i].first;
        A[i].second=i+1;
    }
    sort(all(A));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int k=j+1,l=n-1;
            while(k<l){
                if(A[i].first+A[j].first+A[k].first+A[l].first==x){
                    cout<<A[i].second<<" "<<A[j].second<<" "<<A[k].second<<" "<<A[l].second<<endl;
                    return;
                }
                else if(A[i].first+A[j].first+A[k].first+A[l].first<x) k++;
                else l--;
            }
        }
   }
   cout<<"IMPOSSIBLE"<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}