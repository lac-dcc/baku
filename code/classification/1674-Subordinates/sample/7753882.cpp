#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
vector<int>node[200005];
vector<int>subordinates;
 
void dfs(int s)
{ 
    for(auto &emp:node[s])
    {
        dfs(emp);
        subordinates[s]+=subordinates[emp];
    }
return;
}
 
 
 
 
 void solve(){
       
 int n;cin>>n;
subordinates.assign(n+1,1);
 for(int i=1;i<n;i++)
 {
          int m;
          cin>>m;m--;
        node[m].push_back(i);
 }
dfs(0);
for(int i=0;i<n;i++)cout<<subordinates[i]-1<<" ";
 
return;
}
int main()
{
 
solve();
return 0;
}
