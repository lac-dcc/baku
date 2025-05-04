#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    int m;
    cin>>n;
    cin>>m;
    
    vector<vector<int> > v;
    
    for(int i = 0; i<n; i++){
        
        vector<int> pv;
        v.push_back(pv);
        
    }
    
    vector<int> b;
    for(int i = 0; i<n; i++){
        
        b.push_back(0);
        
    }
    
    for(int i = 0; i<m; i++){
        
        int x;
        int y; 
        cin>>x;
        cin>>y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
 
    }
    
    queue<int> q;
    q.push(0);
    
    vector<int> bv;
    for(int i = 0; i<n; i++){
        
        bv.push_back(0);
        
    }
    
    
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        b[node] = 1;
        for(int i = 0; i<v[node].size(); i++){
            
            if(b[v[node][i]] == 0){
                
                q.push(v[node][i]);
                b[v[node][i]] = 1;
                bv[v[node][i]] = node;
                
            }
            
        }
        
    }
    
    if(b[n - 1] == 0){
        
        cout<<"IMPOSSIBLE"<<endl;
        
    } else {
        
        vector<int> ans;
        ans.push_back(n);
        
        int temp = n - 1;
        
        while(temp!=0){
            
            ans.push_back(bv[temp] + 1);
            temp = bv[temp];
            
        }
        
        cout<<ans.size()<<endl;
        for(int i = (ans.size() - 1); i>=0; i--){
            
            cout<<ans[i]<<" ";
            
        }
        cout<<endl;
        
    }
 
    return 0;
}