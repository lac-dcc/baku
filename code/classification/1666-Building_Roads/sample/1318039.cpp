#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
template <typename T>
class graph{
 
map<T,list<T>> map1;
public:
    void addvertices(T m,T n, bool dirc=true){
        map1[m].push_back(n);
        if(dirc)
            map1[n].push_back(m);
    }
 
    void vertices_helper(map<T,bool> &visited,T src,vector<T> &ans,map<T,int> & m){
        //base case
         visited[src]=true;
         ans.push_back(src);
         m[src]=1;
         for(auto it:map1[src]){
            if(!visited[it]){
                vertices_helper(visited,it,ans,m);
 
            }
 
         }
    }
 
    void find_vertices(int num){
        map<T,bool> visited;
        map<T,int> m;
        vector<T> helper;
        vector<T> ans;
        for(auto it:map1){
            if(!visited[it.first]){
                vertices_helper(visited,it.first,helper,m);
                ans.push_back(helper[helper.size()-1]);
                helper.clear();
            }
        }
 
        vector<T> final_ans;
        for(int i=1;i<=num;i++){
            if(m[i]!=1)
                final_ans.push_back(i);
        }
        int total=ans.size()-1+final_ans.size();
        cout<<total<<endl;
        for(int i=0;i<ans.size()-1;i++){
            cout<<ans[i]<<" "<<ans[i+1]<<endl;
        }
        if(final_ans.size()!=0){
            cout<<ans[ans.size()-1]<<" "<<final_ans[0]<<endl;
 
        for(int i=0;i<final_ans.size()-1;i++)
            cout<<final_ans[i]<<" "<<final_ans[i+1]<<endl;
        
        }
    }
 
 
};
 
int main(){
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	#endif
	//fast io	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    graph<int> g;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g.addvertices(a,b);
    }
 
    g.find_vertices(n);
 
}
 
 
 
