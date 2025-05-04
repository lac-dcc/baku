#include<iostream>
#include<vector>
using namespace std;
class DisjointSet
{
private:
    vector<int> parent,rank;
public:
    DisjointSet(int );
    int findParent(int);
    void joinbyRank(int a,int b);
    void printParent(void);
    ~DisjointSet();
};
int main(){
 
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ds.joinbyRank(a-1,b-1);
    }
    // ds.printParent();
    int no =0;
    vector<int> island;
    for(int i=0;i<n;i++){
        if(ds.findParent(i)==i){
            no++;
            island.push_back(i);
        }
    }
    cout<<no-1<<endl;
    for(int i=1;i<island.size();i++){
        cout<<island[i-1]+1<<" "<<island[i]+1<<endl;
    }
    return 0;
}
 
DisjointSet::DisjointSet(int n)
{
    parent.resize(n);
    rank.resize(n,0);
    for(int i=0;i<n;i++)parent[i] = i;
}
int DisjointSet::findParent(int n){
    if(parent[n]==n)return n;
    else return parent[n] = findParent(parent[n]);
}
void DisjointSet::joinbyRank(int u,int v){
    int u_p = findParent(u);
    int v_p = findParent(v);
    if(u_p==v_p)return;
    if(rank[v_p]>rank[u_p]){
        parent[u_p] = v_p;
    }
    else if(rank[v_p]<rank[u_p]){
        parent[v_p] = u_p;
    }
    else{
        parent[v_p] = u_p;
        rank[u_p]++;
    }
}
void DisjointSet::printParent(){
    for(auto it:parent)cout<<it<<" ";
    cout<<endl;
}
 
DisjointSet::~DisjointSet()
{
}
