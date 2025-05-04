#include<bits/stdc++.h>
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl> p3l;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort(begin(v), end(v))
#define pb push_back
#define int long long
 
 
void solve(){
    int n, target;
    cin>>n>>target;
    vector<array<int,2>> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i][0];
        nums[i][1] = i;
    }
    sort(begin(nums), end(nums));
    int i=0, j=n-1;
    while(i<j){
        if(nums[i][0]+nums[j][0]==target){
            cout<<min(nums[i][1], nums[j][1])+1<<" "<<max(nums[j][1], nums[i][1])+1<<endl;
            return ;
        }
        else if(nums[i][0]+nums[j][0]>target) j--;
        else i++;
    }
    if(i==j) cout<<"IMPOSSIBLE"<<endl;
    return ;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("out.txt","w", stdout);
    #endif
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
 
    return 0; 
}