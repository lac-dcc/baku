#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lint long long
void dfs(int x,int y,int m,int n,vector<string>& arr,vector<vector<int>> &visited){
    visited[x][y] = 1;
    for(int i = -1;i<=1;i++){
        for(int j = -1;j<=1;j++){
            if(abs(i-j) == 1 && x+i >= 0 && x+i<m && y+j >= 0 && y+j < n && !visited[x+i][y+j] && arr[i+x][y+j] == '.'){
                 dfs(x+i,y+j,m,n,arr,visited);
            }
        }
    }
}
int main() {
	// your code goes here
    #ifndef ONLINE_JUDGE
    if (fopen("inputcses.txt", "r"))
    {
        freopen("inputcses.txt", "r", stdin);
        freopen("outputcses.txt", "w", stdout);
    }
    #endif
 
    int m,n;
    cin >> m >> n;
 
    vector<string> arr;
    for(ll i = 0;i<m;i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }
    
    vector<vector<int>> visited(m,vector<int> (n,0));
    
    int count = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            //cout << arr[i][j];
            if(!visited[i][j] && arr[i][j] == '.'){
                count++;
                //cout << i << "  " << j  << arr[i][j];
                dfs(i,j,m,n,arr,visited);
            }
        }
    }
    
    cout << count;
    return 0;
 
}
