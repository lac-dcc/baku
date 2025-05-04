#include<bits/stdc++.h>
using namespace std;
 
int sub_counts[1000001];
 
void fill_count(vector<int> g[],int node,int parent){
 
    sub_counts[node]++;
    for(int i=0;i<g[node].size();i++){
        int ch = g[node][i];
        if(ch != parent){
            fill_count(g,ch,node);
            sub_counts[node] += sub_counts[ch];
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> g[n+1];
    for(int i=0;i<n-1;i++){
        int k;
        cin>>k;
        g[i+2].push_back(k);
        g[k].push_back(i+2);
    }
    fill_count(g,1,0);
    for(int i=1;i<=n;i++){
        cout<<sub_counts[i]-1<<" ";
    }
}
