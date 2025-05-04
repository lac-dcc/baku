#include <bits/stdc++.h>
 
using namespace std;
 
#define ld long double
#define ll long long
#define mn(a,b,c) min(min(a,b),c)
#define mx(a,b,c) max(max(a,b),c)
 
ll mod=pow(10,9)+7;
 
int ans{};
 
int dia(vector<vector<int>>&v, int curr, int par){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto &c:v[curr]){
        if(c!=par){
            pq.push(dia(v,c,curr));
            if(pq.size()>2){
                pq.pop();
            }
        }
    }
    if(pq.empty()){
        return 0;
    }
    else if(pq.size()==1){
        ans=max(ans,pq.top()+1);
        return pq.top()+1;
    }
    int h1=pq.top();
    pq.pop();
    int h2=pq.top();
    pq.pop();
 
    ans=max(ans,h1+h2+2);
 
    return max(h1,h2)+1;
 
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
 
    vector<vector<int>>v(n);
 
    int a,b;
    for(int i{};i<n-1;++i){
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
 
    dia(v,0,-1);
    cout<<ans<<endl;
 
    return 0;
 
}
