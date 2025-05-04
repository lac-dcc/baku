//https://cses.fi/problemset/task/1619
//@author :: Abhimanyu Chauhan
 
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
 
 
#define MOD			1000000007
#define oo			INT_MAX/2
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)		for(int i=k;i<n;i++)
#define deb(x)			cout << #x << " " << x << endl
 
using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;
 
template<typename T>
istream& operator >> (istream& in , vector<T> &ar){
    for (int i = 0 ; i < (int) ar.size() ; i++) in >> ar[i];
return in;
}
 
template<typename T>
ostream& operator << (ostream& out , vector<T> &ar){
    for (int i = 0 ; i < (int) ar.size() ; i++) out << ar[i] << " ";
    cout << '\n';
return out;
}
 
int main(){
 
#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif
 
    ios_base::sync_with_stdio(0);cin.tie(0);
 
    int n ;
    cin >> n;
    
    vector<pair_int> ar;
    vector<int> cc;
    cc.pb(0);
    for(int i=0;i<n;i++){
        int u , v;
        cin >> u >> v;
        ar.pb({u,v});
        cc.pb(u);cc.pb(v);
    }
 
    sort(all(cc));
 
    auto get = [&](int x){
        return lower_bound(all(cc) , x) - cc.begin();
    };
 
    vector<int> pre(cc.size() + 2 , 0);
    for(auto i : ar){
        pre[get(i.f)]++;
        pre[get(i.s)+1]--; 
    }
 
    for(int i= 1 ;i<=cc.size();i++){
        pre[i]+=pre[i-1];
    }
    // cout << pre;
    cout << *max_element(all(pre)) << '\n';
    return 0;
}
