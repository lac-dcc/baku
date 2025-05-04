#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define pi 3.1415926536
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bs binary_search
#define int long long
#define float double
#define mii map<int,int>
#define mci map<char,int>
#define msi map<string,int>
#define mss map<string,string>
#define mcc map<char,char>
#define mpi map<pair<int,int>,int>
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define ss set<string>
#define sc set<char>
int const max1= 2e6;
int const mod = 1e9+7;
int inf = 1e18;
 
bool comp(pair<int,int> &a,pair<int,int> &b){
    if(a.S!=b.S){
        return a.S<b.S;
    }
    return a.F<b.F;
}
 
void solve(){
    int n,k;
    cin>>n>>k;
    multiset<int> s;
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p[i]  ={x,y};
    }
    sort(p,p+n,comp);
    // for(int i=0;i<n;i++){
    //     cout<<p[i].F<<" "<<p[i].S<<endl;
    // }
    s.insert(p[0].S);
    int ans = 1;
    for(int i=1;i<n;i++){
        int x = p[i].F;
        int y = *s.begin();
        //cout<<i+1<<" - "<<y<<" ";
        if(x>=y){
            //cout<<"taken";
            ans++;
            auto it = s.upper_bound(x);
            it--;
            s.erase(it);
            s.insert(p[i].S);
        }
        else{
            if(s.size()<k){
                ans++;
                //cout<<"New";
                s.insert(p[i].S);
            }
        }
        // cout<<endl;
    }
    cout<<ans;
}
 
int32_t main(){
ios::sync_with_stdio(0);
cin.tie(0);
int tc=1;
//cin>>tc;
while(tc--){
    solve();
}
}