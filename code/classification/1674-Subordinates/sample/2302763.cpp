#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
 
int n;
vector<int> v[200001];
vector<int> s(200001);
int bfs(int i){
    s[i]=0;
    for(auto u:v[i]){
        s[i]+=bfs(u)+1;
    }
    return s[i];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        v[a].push_back(i);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<s[i]<<" ";
    }
	return 0;
}
