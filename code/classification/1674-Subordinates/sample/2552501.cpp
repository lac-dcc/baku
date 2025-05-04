#include <bits/stdc++.h> 
using namespace std;
 
#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
 
void findNumOfSubordinates(ll curr, vector<vector<ll> >& children, vector<ll>& numOfSub){
    ll val = 0;
    for(ll i=0;i<children[curr].size();i++){
        findNumOfSubordinates(children[curr][i],children,numOfSub);
        val += numOfSub[children[curr][i]] + 1;
    }
    numOfSub[curr] = val;
}
 
int main(){
    ll n;
    cin >> n;
    vector<vector<ll> > children(n+1,vector<ll>(0));
    for(ll i=2;i<=n;i++){
        ll boss;
        cin >> boss;
        children[boss].pb(i);
    }
    vector<ll> numOfSub(n+1,0);
    findNumOfSubordinates(1,children,numOfSub);
    for(ll i=1;i<=n;i++){
        cout << numOfSub[i] << " ";
    }
    cout << endl;
}
