#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
struct ii{
    ll x;
    ll id;
};
 
bool cmp(ii a, ii b){
    return a.x<b.x || (a.x==b.x && a.id<b.id);
}
 
 
int main(){
    int n;
    cin>>n;
    vector<ii> k(2*n+1);
    for(int i=1;i<=2*n;i++){
        cin>>k[i].x;
        k[i].id = i%2;
    }
    sort(k.begin()+1,k.end(),cmp);
    int res = 0;
    int tp = 0;
    for(int i=1;i<=2*n;i++){
        if(k[i].id == 1){
            tp++;
            res = max(res,tp);
        }
        else{
            tp--;
        }
    }
    cout<<res;
    return 0;
}
