#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include <fstream>
using namespace std;
const long long N = 1000;
vector<int> adj[N];
bool vist[N][N];
char arr[N][N];
void dfs(int i , int j , int n , int m){
    vist[i][j] = true;
    if(arr[i-1][j] == '.' && vist[i-1][j] == false && i !=0) dfs(i-1 , j , n , m);
    if(arr[i][j-1] == '.' && vist[i][j-1] == false && j != 0) dfs(i , j-1 , n, m);
    if(arr[i+1][j] == '.' && vist[i+1][j] == false && i !=n-1) dfs(i+1 , j , n , m);
    if(arr[i][j+1] == '.' && vist[i][j+1] == false && j != m-1) dfs(i , j+1 , n, m);
 
}
int main() {
    long long n , m , count = 0 ;
    cin>>n>>m;
    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < m ; j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0 ; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            if (vist[i][j] == true) continue;
            else if(arr[i][j]=='.'){
                dfs(i, j ,n, m);
                count++;
            }
        }
    }
    cout<<count;
 
 
}
