#include <bits/stdc++.h>
using namespace std;
 
//debug..........
#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x;while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}
#define int long long
 
const int N = 2e5;
 
struct node{
    int sum , pref , suff , ans;
};
 
int a[N];
node st[4*N];
 
node combine(node l , node r){
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref , l.sum + r.pref);
    res.suff = max(r.suff , r.sum + l.suff);
    res.ans = max({l.ans , r.ans , l.suff + r.pref});
    return res;
}
 
node make_node(int val){
    node res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0LL , val);
    return res;
}
 
void build(int idx , int ss , int se){
    if(ss == se){
        st[idx] = make_node(a[ss]);
        return ;
    }
    int mid = (ss+se) / 2;
    build(idx*2 , ss,mid);
    build(idx*2+1 , mid+1, se);
    st[idx] = combine(st[idx*2] , st[idx*2+1]);
}
 
void update(int idx , int ss , int se, int x, int val){
    if(x < ss or se < x)return;
    if(ss == se){
        st[idx] = make_node(val);
        return ;
    }
    int mid = (ss + se) / 2;
    update(idx*2 , ss , mid , x, val);
    update(idx*2+1 , mid + 1 , se , x , val);
    st[idx] = combine(st[idx*2] , st[idx*2+1]); 
    // error(idx , st[idx].sum , st[idx].pref , st[idx].suff)
}
 
node query(int idx , int ss, int se , int qs , int qe){
    if(qe < ss or se < qs){
        return make_node(0);
    }
    if(qs <= ss and se <= qe){
        return st[idx];
    }
    int mid = (ss + se) / 2;
    node l = query(idx*2 , ss , mid , qs , qe);
    node r = query(idx*2+1,  mid+1 , se , qs , qe);
    return combine(l , r);
}
 
signed solve(){
 
    int n,q;
    cin>>n>>q;
 
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
 
    build(1,1,n);
 
    // for(int  i=1;i<=2*n;i++){
    //     cout<<st[i].pref<<" ";
    // }cout<<endl;
 
    int t,x,y;
    while(q--){
        cin>>t>>x>>y;
        if(t == 1){
            update(1,1,n,x,y);
        }else{
            node val = query(1,1,n,x,y);
            cout<<(val.pref)<<endl;;
        }
    }
 
 
    return 0;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);int test = 1;
    // cin>>test;
    while (test--)solve();return 0;
}
