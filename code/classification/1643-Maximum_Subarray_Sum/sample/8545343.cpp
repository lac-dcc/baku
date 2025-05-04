#include <bits/stdc++.h>
#define HABIBA  ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define PP push_back
#define LL long long
#define F first
#define S second
#define lp int Q; cin >>Q; while (Q--)
#define inp for(LL i=0; i<n;i++){cin >>a[i];}
#define sorting sort (a,a+n);
#define outp for (LL I=0; I<N;I++) {cout <<ARRAY[I]<<"\n";}
#define cout(X) for(auto V:X)cout<<V<<"\n";
#define coutp(X) for(auto V:X)cout<<V.F<<' '<<V.S<<'\n';
#define cin(X) for(auto &V:X)cin>>V;
#define pb(X) push_back(X);
#define all(X)  X.begin(),X.end()
#define OR or
#define AND and
const LL MOD = 1e9 + 7;
const LL N = 1e5 + 7;
using namespace std;
int main() {
HABIBA
//lp {
int n;
cin >>n;
LL a[n]; inp;
LL c_s=a[0], t_s=a[0];
for (int i=1; i<n;i++){
c_s= max(c_s+a[i], a[i]);
t_s= max(c_s, t_s);	
} cout <<t_s;
//}
return 0;
}