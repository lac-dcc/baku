/// Rex
#include<bits/stdc++.h>
 
#define foru(i,d,c) for(int i=d;i<=c;++i)
#define ford(i,c,d) for(int i=c;i>=d;--i)
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,i>
#define fi first
#define se second
#define bit(x,i) ((x>>i)&1)
#define off(x,i) (x^(1<<i))
#define on(x,i) (x|(1<<i))
#define mini(x,y) x=min(x,y)
#define maxi(x,y) x=max(x,y)
#define log2(x) (32-__builtin_clz(x))
#define cntbit(x) __builtin_popcount(x)
const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
using namespace std;
 
int n,m;
map<int,int> M;
map<int,int> :: iterator it;
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	#ifndef ONLINE_JUDGE
	#define taskname "CT."
	freopen(taskname"inp","r",stdin);
	freopen(taskname"out","w",stdout);
	#endif //ONLINE_JUDGE
 
    cin >> n >> m;
    foru(i,1,n){
        int x;
        cin >> x;
        ++M[-x];
    }
 
 
    foru(i,1,m){
        int x;
        cin >> x;
        it = M.lower_bound(-x);
        if(it == M.end())
            cout << -1 <<"\n";
        else{
            cout << -(*it).first <<"\n"; if(!--M[(*it).first]) M.erase(it);}
    }
 
 
 
 
 
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
