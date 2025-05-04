// priority_queue is generally max heap to make it min heap use priority_queue<int,vector<int>,greater<int>> pq;"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int                 long long int
#define double              long double
#define db(x)               cout<<"["<<x<<"]"<<endl;
#define db1(x)               cout<<"{"<<x<<"}"<<endl;
#define db2(x)               cout<<"("<<x<<")"<<endl;
#define endl                "\n"
#define Endl                endl
#define itn                 int
#define PI                  acos(-1)
#define pb                  push_back
#define all(a)              a.begin(),a.end()
#define mod                 1000000007
#define if9                 if(
#define goog(t,ans)         cout<<"Case #"<<t<<": "<<ans<<endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> //less_equal.
//                                       ^ here if we write less_equal<int> then it is an ordered multiset.
using namespace std;
using namespace __gnu_pbds;
 
template<typename T>
void inp(T &a) {
    cin >> a;
}
 
template<typename T, typename ...Arg>
void inp(T &a1, Arg ...a) {
    inp(a1);
    inp(a...);
}
 
template<typename Arg1>
void inp1(const char *name, Arg1 &&arg1) {
    inp(arg1);
}
 
template<typename Arg1, typename ... Args>
void inp1(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket = 0, i = 0;
    for (;; i++)
        if (names[i] == ',' && bracket == 0)
            break;
        else if (names[i] == '(')
            bracket++;
        else if (names[i] == ')')
            bracket--;
    const char *comma = names + i;
    inp(arg1);
    inp1(comma + 1, args...);
}
 
#define get(...) inp1(#__VA_ARGS__, __VA_ARGS__)
 
template<typename T>
void __p(T a) {
    cout << "(" << a << ")";
}
 
template<typename T, typename F>
void __p(pair<T, F> a) {
    cout << "(";
    cout << a.first;
    cout << ",";
    cout << a.second;
    cout << ")";
}
 
template<typename T>
void __p(std::vector<T> a) {
    for (auto it = a.begin(); it < a.end(); it++)
        cout << *it << " ";
}
 
template<typename T>
void __p(std::set<T> a) {
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
}
 
template<typename T>
void __p(std::multiset<T> a) {
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
}
 
template<typename T, typename F>
void __p(std::map<T, F> a) {
    for (auto it = a.begin(); it != a.end(); ++it) {
        cout << it->first << " ";
        cout << it->second << " ";
        cout << endl;
    }
}
 
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
    __p(a1);
    __p(a...);
}
 
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    __p(arg1);
    cout << endl;
}
 
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket = 0, i = 0;
    for (;; i++)
        if (names[i] == ',' && bracket == 0)
            break;
        else if (names[i] == '(')
            bracket++;
        else if (names[i] == ')')
            bracket--;
    const char *comma = names + i;
    __p(arg1);
    cout << ",";
    __f(comma + 1, args...);
}
 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
 
vector<int> sz(200001);
vector<int> v[200001];
int dfs(int n,int par){
    int sum=0;
    for(auto ch : v[n]){
        if(ch!=par){
            sum+=dfs(ch,n);
        }
    }
    sz[n] = sum;
    return sum+1;
}
 
void solve() {
    int n;
    cin>>n;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin>>x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    dfs(1,-1);
    for (int i = 1; i <=n ; ++i) {
        cout<<sz[i]<<" ";
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(15);
//    std::ifstream in("file.in");
//    std::ofstream out("file.out");
    //sieve();
    //fact();
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
