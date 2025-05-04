#define el                   endl
#define pb                   push_back
#define ll                   long long int
#define vl                   vector<long long int>
#define vb                    vector<bool>
#define vi                    vector<int>
#define pii                  pair<int,int>
#define mii                  map<int,int>
#define IOS                 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#include<bits/stdc++.h>
using namespace std;
 
 
 
void sol(){
   int n; cin>>n;
   vector<pair<ll,ll>> t(n);
   for(auto &it:t) cin>>it.first>>it.second;
   sort(t.begin(),t.end());
   priority_queue<ll> pq;
   int ret = 0;
   for(int i=0;i<n;i++){
      while(!pq.empty()&&-pq.top()<t[i].first) pq.pop();
      pq.push(-t[i].second);
      ret = max(ret,(int)pq.size());
   }
   cout<<ret;
}
 
int main(){
IOS;
int t=1;
// cin>>t;
while(t-->0)
     sol();
}
