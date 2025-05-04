#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> edges;
vector<multiset<int>> child;
vector<int> h, ans;
 
void dfs(int v,int p, int height){
    int mh=0;
    for(auto ch:edges[v]){
        if(ch!=p)   {
            dfs(ch,v,height+1);
            mh=max(mh,1+h[ch]);
            child[v].insert(1+h[ch]);
        }
    }            
    h[v]=mh;
}
 
void dfs2(int v, int p=-1){
    for(auto ch:edges[v]){
        if(ch!=p)   {
            child[v].erase(child[v].find(1+h[ch]));
            if(child[v].size()==0)  child[ch].insert(1);
            else{
                auto it=child[v].end();
                --it;
                int mh=*it;
                child[ch].insert(1+mh);
            }
            auto it=child[ch].end();
            --it;
            ans[ch]=*it;
             child[v].insert(1+h[ch]);
            dfs2(ch,v);
        }
    }
}
 
int main(){
    int n,i,mh=0,mv;
    cin>>n;
    edges=vector<vector<int>>(n);
    child=vector<multiset<int>>(n);
    ans=h=vector<int>(n,0);
    for(i=1;i<n;i++){
        int a,b;    cin>>a>>b;
        a--;    b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0,-1,0);
    ans[0]=*max_element(h.begin(), h.end());
    dfs2(0);
    for(auto aa:ans)    cout<<aa<<" ";
    return 0;
}
