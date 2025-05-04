#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS         ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb          push_back
#define ub          upper_bound
#define lb          lower_bound
#define F(i, a, b)  for(int i = a; i < b; ++i)
#define R(i, a, b)  for(int i = a; i >= b; --i)
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int N = 1e3+4;
vector<string> a(N);int n,m;
 
bool check(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m && a[i][j]=='.') return true;
    return false;
}
 
void dfs(int i,int j){
    a[i][j] = '#';
    if(check(i-1,j)) dfs(i-1,j);
    if(check(i+1,j)) dfs(i+1,j);
    if(check(i,j-1)) dfs(i,j-1);
    if(check(i,j+1)) dfs(i,j+1);
}
 
int32_t main()
{
    IOS;
    cin >> n >> m;
    F(i,0,n){
        cin >> a[i];
    }
    int ans =0;
    F(i,0,n){
        F(j,0,m){
            if(check(i,j)){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
