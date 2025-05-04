#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 1 ;
 
vector<int>adj[N] ;
int max_path[N] ;
int dp[N][2] ;
 
int n , x , y ;
 
void dfs1(int now , int pa){
 
    int temp = 0 ;
    int max_1 = 0 ;
    int max_2 = 0 ;
    int max_node ;
 
    for(auto i : adj[now]){
        if(i == pa)continue;
        dfs1(i , now) ;
        
        temp = 1 + dp[i][1] ;
 
        if(temp > max_1){
            max_2 = max_1 ;
            max_1 = temp ;
            max_path[now] = i ;
 
            dp[now][0] = dp[now][1] ;
            dp[now][1] = max_1 ;
        }
        else if(temp > max_2){
            max_2 = temp ;
            dp[now][0] = max_2 ;
        }
    }
}
 
void dfs2(int now , int pa){
 
    
    if(now != 1){
        if(max_path[pa] == now){
 
            int temp1 , temp2 ;
            temp1 = 1 + dp[pa][0] ;
            temp2 = dp[now][1] ;
            if(temp1 > temp2){
                max_path[now] = pa ;
                dp[now][1] = temp1 ;
            }
            else {
                dp[now][1] = temp2 ;
                dp[now][0] = max(dp[now][0] , temp1) ;
            }
        }
        else {
            int temp1 , temp2 ;
            temp1 = 1 + dp[pa][1] ;
            temp2 = dp[now][1] ;
 
            if(temp1 > temp2){
                max_path[now] = pa ;
                dp[now][1] = temp1 ;
            }
            else {
 
                dp[now][1] = temp2 ;
                dp[now][0] = max(dp[now][0] , temp1) ;
 
            }
        }
    }
 
    
 
    for(auto i : adj[now]){
        if(i == pa)continue;
        dfs2(i , now) ;
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(0) , cin.tie(0) ;
 
    cin >> n ;
 
    for(int i = 1 ; i <= n - 1 ; i ++ ){
 
        cin >> x >> y ;
 
        adj[x].push_back(y);
        adj[y].push_back(x);
 
    }
 
    dfs1(1 , -1);
    dfs2(1 , -1);
 
    for(int i = 1 ; i <= n ; i ++ ){
        cout << dp[i][1] << ' ' ;
    }
 
    return 0 ;
}
