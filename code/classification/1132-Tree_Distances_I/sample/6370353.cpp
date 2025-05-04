#include <iostream>
#include <vector>
using namespace std;
 
int n;
vector <int> graph[200000];
vector <int> tree[200000];
vector <int> pre[200000];
vector <int> suf[200000];
vector <int> md[200000];
int parent[200000];
int pc[200000];
bool vis[200000];
int upans[200000];
int depth[200000];
int mcd[200000];
int answ[200000];
 
int gendepth(int p, int d) {
    //cout << p << " " << d << endl;
    vis[p] = true;
    int ans = d;
    for (int i=0; i<graph[p].size(); i++) {
        if (vis[graph[p][i]]) {
            continue;
        }
        tree[p].push_back(graph[p][i]);
        parent[graph[p][i]] = p;
        pc[graph[p][i]] = tree[p].size()-1;
        md[p].push_back(gendepth(graph[p][i],d+1));
        ans = max(md[p].back(),ans);
    }
    pre[p].resize(md[p].size()+1);
    suf[p].resize(md[p].size()+1);
    pre[p][0] = 0;
    for (int i=1; i<=md[p].size(); i++) {
        pre[p][i] = max(md[p][i-1],pre[p][i-1]);
    }
    suf[p][md[p].size()] = 0;
    for (int i=md[p].size()-1; i>=0; i--) {
        suf[p][i] = max(md[p][i],suf[p][i+1]);
    }
    depth[p] = d;
    mcd[p] = ans;
    return ans;
}
 
void genans(int p) {
    if (p!=0) {
        answ[p] = max(pre[parent[p]][pc[p]],suf[parent[p]][pc[p]+1])+2-depth[p];
        answ[p] = max(answ[p],upans[parent[p]]+1);
        upans[p] = answ[p];
    }else{
        upans[p] = 0;
        answ[p] = 0;
    }
    answ[p] = max(answ[p],mcd[p]-depth[p]);
    
    for (int i=0; i<tree[p].size(); i++) {
        genans(tree[p][i]);
    }
}
 
int main() {
    cin >> n;
    int x,y;
    for (int i=0; i<n-1; i++) {
        cin >> x >> y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    gendepth(0,0);
    parent[0] = -1;
    for (int i=0; i<n; i++) {
        vis[i] = false;
    }
    genans(0);
    /*for (int i=0; i<n; i++) {
        if (i!=0) {
            cout << i << ":" <<mcd[i] << "-" << depth[i] << "-" << pre[parent[i]][pc[i]] << "-" << suf[parent[i]][pc[i]+1] << " " << pc[i] << "-" << upans[parent[i]] << " " << parent[i] << endl;
        }else{
            cout << i << ":" << mcd[i] << "-" << depth[i] << endl;
        }
    }cout << endl;*/
    for (int i=0; i<n; i++) {
        cout << answ[i] << " ";
    }
}
