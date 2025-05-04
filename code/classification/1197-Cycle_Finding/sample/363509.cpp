//
//  main.cpp
//  Cycle Finding
//
//  Created by Yousef on 20.03.20.
//
 
#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m, a, b;
    long long c, inf = 1e16;
    cin>>n>>m;
    vector<tuple<int, int, long long>> adj;
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
    }
    vector<long long> dist (n + 1, inf);
    vector<int > parent (n + 1, - 1);
    vector<bool > visited (n + 1, false);
    
 
 
            dist[1] = 0;
            visited[1] = true;
            for(int i = 0; i < n - 1; i++)
              {
                  for(auto e: adj)
                  {
                      a = get<0>(e);
                      b = get<1>(e);
                      c = get<2>(e);
                      if(dist [b] > dist [a] + c)
                      {
                          dist [b] = dist[a] + c;
                          visited[b] = true;
                          parent[b] = a;
                      }
                  }
              }
    
    bool found = false;
    int start;
    for(auto e: adj)
    {
        a = get<0>(e);
        b = get<1>(e);
        c = get<2>(e);
        
        if(dist [b] > dist [a] + c)
            {
                parent[b] = a;
                found = true;
                start = b;
                break;
            }
    }
    
    if(found)
    {
        cout<<"YES"<<"\n";
        stack<int> s;
        vector<bool> visited (n + 1, false);
        
        while(true)
        {
            if(visited[start])
                break;
            visited[start] = true;
            start = parent[start];
        }
        int temp = start;
        
        do
        {
            
            s.push(start);
            start = parent [start];
            
        }while(start != temp);
        
        s.push(start);
        
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        
        
        return 0;
    }
    else
    {
        cout<<"NO";
    }
    
    
    
    return 0;
}
