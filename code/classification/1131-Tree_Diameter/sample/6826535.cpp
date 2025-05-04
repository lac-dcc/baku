// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
#define endl "\n"
#define int long long int
 
int diameter = 0 ;
 
int solve(vector<vector<int>>& v , int node,set<int> &  visited){
       if(visited.count(node)) return 0;
       visited.insert(node);
 
       int first_max=0,second_max = 0;
 
       for(auto & val : v[node]){
          int x = solve(v,val,visited);
 
          if(x>first_max){
            second_max= first_max;
            first_max = x;
          }else second_max = max(second_max, x);
 
       }
 
       diameter = max(diameter , first_max+second_max);
 
       return first_max+1;
}
 
signed main(){
    int n;
    cin>>n;
    vector<vector<int>>v (n+1);
    for(int i=1;i<n;i++){
        int x, y ;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    set<int>  visited;
 
     solve(v,1, visited);
     cout<<diameter<<endl;
 
}
