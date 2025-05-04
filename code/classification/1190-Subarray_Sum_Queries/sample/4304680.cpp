#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int n,q;
 
//*===== Segment Tree =====
vector<ll> subans,subL,subR,subsum;
 
void Build(int a[], int x=1, int L=1, int R=n){
    if(L==R) {subans[x]=subL[x]=subR[x]=subsum[x]=1ll*a[L]; return;}
    int M=(L+R)/2;
    Build(a, x*2,   L,   M);
    Build(a, x*2+1, M+1, R);
    
    subans[x] = max({subans[x*2], subans[x*2+1], subR[x*2]+subL[x*2+1]});
    subR[x]   = max(subR[x*2+1],  subsum[x*2+1]+subR[x*2]);
    subL[x]   = max(subL[x*2],    subsum[x*2]+subL[x*2+1]);
    subsum[x] = subsum[x*2] + subsum[x*2+1];
}
void Update(int pos, ll k, int x=1, int L=1, int R=n){
    if(L==R) {subans[x]=subL[x]=subR[x]=subsum[x]=k; return;}
    int M=(L+R)/2;
    if(pos<=M) Update(pos, k, x*2,   L,   M);
    else       Update(pos, k, x*2+1, M+1, R);
    
    subans[x] = max({subans[x*2], subans[x*2+1], subR[x*2]+subL[x*2+1]});
    subR[x]   = max(subR[x*2+1],  subsum[x*2+1]+subR[x*2]);
    subL[x]   = max(subL[x*2],    subsum[x*2]+subL[x*2+1]);
    subsum[x] = subsum[x*2] + subsum[x*2+1];
}
//========================*
 
int main(){
    scanf("%d%d",&n,&q);
    int a[n+1], k,x;
    subans.resize(n*4); subR.resize(n*4); subL.resize(n*4); subsum.resize(n*4);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    Build(a);
    while(q--)
        scanf("%d%d",&k,&x),
        Update(k,1ll*x),
        printf("%lld\n",(subans[1]<0)? 0:subans[1]);
}
