#include <bits/stdc++.h>
#define HABIBA  ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define PP push_back
#define LL long long
#define F first
#define S second
#define lp int Q; cin >>Q; while (Q--)
#define inp for(LL i=0; i<number;i++){cin >>array[i];}
#define sorting sort (a,a+n);
#define outp for (LL I=0; I<N;I++) {cout <<ARRAY[I]<<"\n";}
#define cout(X) for(auto V:X)cout<<V<<"\n";
#define coutp(X) for(auto V:X)cout<<V.F<<' '<<V.S<<'\n';
#define cin(X) for(auto &V:X)cin>>V;
#define pb(X) push_back(X);
#define all(X)  X.begin(),X.end()
#define OR or
#define AND and
#define show_it cin
#define show_me cout
const LL MOD = 1e9 + 7;
const LL N = 1e18;
using namespace std;
int main() {
HABIBA
//lp {
int number, number_bardo;
show_it >> number>>number_bardo;
vector <pair<int,int>> array;
for (int i=0; i<number;i++){
int tempoo;
cin >>tempoo;
array.push_back({tempoo,i});	
}
sort(all(array));
for (int i=0; i<number;i++){
int number_bardoo= number_bardo-array[i].F;	
for (int j=i+1; j<number;j++){
int number_bardooo=number_bardoo-array[j].F;	
int pointer=j+1, pointer_bardo=number-1;
//show_me <<array[i].S+1<<" "<<array[j].S+1<<" "<<array[pointer].S+1<<" "<<array[pointer_bardo].S+1<<"\n";
while (pointer<pointer_bardo){
if (array[pointer].F+array[pointer_bardo].F<number_bardooo) pointer++;	
else if (array[pointer].F+array[pointer_bardo].F>number_bardooo) pointer_bardo--;	
else {show_me <<array[i].S+1<<" "<<array[j].S+1<<" "<<array[pointer].S+1<<" "<<array[pointer_bardo].S+1; return 0;}
}}} show_me <<"IMPOSSIBLE";
//}
return 0;
} 
