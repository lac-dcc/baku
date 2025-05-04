#include <bits/stdc++.h>
using namespace std;
// #define int long long 
typedef pair<int, int> pii; 
#define ll long long
#define ld long double
#define ar array
const int mxN=1e5+4;
const int mod=1e9+7;
// const int mod=998244353;
const ll INF=1e17;
#define what_is(x) cerr << #x << " is " << x << endl;
using Matrix = vector<vector<long long>>;
using vll = vector<long long>;
using cd =complex<double>;
const double PI= acos(-1);
typedef pair<int,int> pi;
clock_t begtime = clock();
 
 
 
#define timetaken() cout << "\n\nTime elapsed: " << (float)(clock() - begtime)/1000.0
 
// inline int64_t mul(int64_t a, int64_t b){
//  return (INF/a >b ? a*b : INF);
// }
 
 
// inline int64_t add(int64_t a, int64_t b){
//  return (a+b >=INF ? INF : a+b);
// }
 
// template <class T1, class T2, class Pred = std::less<T2> >
// struct sort_pair_second {
//     bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
//         Pred p;
//         return p(left.second, right.second);
//     }
// };
struct cmp{
    public:
        bool operator()(const array<int,2>&a,const  array<int,2>&b){
            return a[0]<b[0];
        }
}cmp;
 
//________________________________________________________________________________________
 
 
 
void solve(){ 
 
    int n,k;
    cin>>n>>k;
    multiset<int> person;
    for(int i=0;i<k;i++){
        person.insert(0);
    }
    vector<array<int,2>> v(n);
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        v[i][0]=b; v[i][1]=a;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        auto itr=person.upper_bound(v[i][1]);
 
        if(itr!=person.begin()){
            itr--;
            person.erase(itr);
            person.insert(v[i][0]);
            ans++;
        }
    }
    cout<<ans<<endl;
}       
// edge case n=1       
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif  
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    // fflush(stdout);
    // cout<<setprecision(10)<<fixed;
    // timetaken();
    ll t=1;
    // cin>>t;
    // seive();
    int i=1;
 
    while(t--){
        // cout<<"Case #"<<i<<": ";
        solve();
        // cout<<endl;
        i++;
    }
    return 0;
   
}  