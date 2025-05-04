#include <bits/stdc++.h>
 
using namespace std;
 
const int OFF = (1<<18);
const long long NEG = -1e15;
const long long llnula = 0;
 
struct node {
    long long tour, suf, pref, cij;
};
 
node tour[2*OFF];
int n,m;
 
node spoji(node l, node r) {
    node n;
    n.cij = l.cij+r.cij;
    n.suf = max(r.suf, r.cij+l.suf);
    n.pref = max(l.pref, l.cij+r.pref);
    n.tour = max(l.tour, max(r.tour,l.suf+r.pref));
    return n;
}
 
void update(int x, int v){
    x += OFF;
    tour[x] = {v,v,v,v};
    x/=2;
    while(x>0){
        tour[x] = spoji(tour[2*x], tour[2*x+1]);
        x/=2;
    }
}
 
node query(int a, int b,int x = 1, int lo = 0, int hi = OFF){
    if(b<=lo||hi<=a){
        return {NEG, NEG, NEG, NEG};
    }
    if(lo>=a&&hi<=b){
        return tour[x];
    }
    int mid = (lo+hi)/2;
    return spoji(query(a,b,x*2,lo,mid), query(a,b,x*2+1,mid,hi));
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int a;
        cin >> a;
        update(i,a);
    }
    for(int i = 0;i<m;i++){
        int b,c;
        cin >> b >> c;
 
        update(b-1,c);
        cout << max (llnula, query(0, n).tour) << "\n";
    }
    return 0;
}
 
 
