#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<map>
#include<bitset>
#include<climits>
#include<queue>
#include<stack>
#include<cmath>
 
 
using namespace std;
 
 
# define itn int
# define LOG(x) cout << x << endl
typedef long long ll;
 
 
void solve(){
 
}
 
 
int main()
{
    int n, x;
    cin >> n >> x;
 
    int S[n], H[n];
    for(int i=0; i<n; i++){
        cin >> H[i];
    }
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
 
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[x+1];
        for(int j=0; j<=x; j++){
            dp[i][j] = 0;
        }
    }
 
    if(x >= H[0])
        dp[0][H[0]] = S[0];
 
 
    int max_pages = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<=x; j++){
            if(H[i] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-H[i]] + S[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            max_pages = max(max_pages, dp[i][j]);
        }
    }
 
    LOG(max_pages);
 
    return 0;
}