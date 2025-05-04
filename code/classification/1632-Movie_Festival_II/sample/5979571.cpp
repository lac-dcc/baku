#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<string>
#include<list>
#include<utility>
#include<stack>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<functional>
#include<cstring>
#include<ctime>
#include <climits>
#define ll         long long
#define VVpii     vector<vector<pair<ll,ll>>>
#define X          first
#define Y          second
#define mk       make_pair
#define pb        push_back
#define N          200005
#define Vi         vector<ll>
#define VVi      vector<vector<ll>>
#define rs         resize
#define sz         size()
#define all(v)   (v).begin(),(v).end()
#define ub        upper_bound
#define lb          lower_bound
#define pii       pair<ll,ll>
#define gr        greater
#define llmx  LONG_LONG_MAX
#define imx    INT_MAX
#define rep(x,a,b) for(ll x=a;x<=b;x++)
#define Vpii    vector<pair<ll,ll>>
using namespace std;
struct st{
    int a,b;
};
bool cmp(st x,st y){
    return x.b>y.b;
}
const int mod=1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<st> v(n);
    rep(i,0,n-1){
        cin>>v[i].a>>v[i].b;
    }
    sort(all(v),cmp);
    multiset<int> s;
    rep(i,1,k)s.insert(imx);
    int ans=0;
    rep(i,0,n-1){
        auto t=s.end();
        t--;
        if(v[i].b<=*t){
            s.erase(t);
            s.insert(v[i].a);
            ans++;
            continue;
        }
        t=s.begin();
        if(v[i].a>*t){
            s.erase(t);
            s.insert(v[i].a);
        }
    }
    cout<<ans<<"\n";
}