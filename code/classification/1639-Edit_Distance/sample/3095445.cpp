#include <bits/stdc++.h>
 
using namespace std;
string u, v;
int recursiva(int i, int j){
    if(!i && !j){
        return 0;
    }
    if(!i){
        return recursiva(i, j - 1) + 1;
    }
    if(!j){
        return recursiva(i - 1, j) + 1;
    }
    if(u[i - 1] == v[j - 1]){
        return recursiva(i - 1, j - 1);
    }
    return min(recursiva(i - 1, j - 1), min(recursiva(i - 1, j), recursiva(i, j - 1))) + 1;
}
int memo[1002][1002];
int memorizada(int i, int j){
    if(!i && !j){
        return 0;
    }
    if(memo[i][j] == -1){
        if(!i){
            memo[i][j] = memorizada(i, j - 1) + 1;
        }
        else if(!j){
            memo[i][j] = memorizada(i - 1, j) + 1;
        }
        else if(u[i - 1] == v[i - 1]){
            memo[i][j] = memorizada(i - 1, j - 1);
        }
        else{
            memo[i][j] = min(memorizada(i - 1, j - 1), min(memorizada(i, j - 1), memorizada(i - 1, j))) + 1;
        }
    }
    return memo[i][j];
}
int dp[2][5002];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> u >> v;
    //iterativa
    int lon1 = u.size(), lon2 = v.size();
    for(int i = 0; i <= lon1; ++i){
        for(int j = 0; j <= lon2; ++j){
            if(!i && !j){
                continue;
            }
            if(!i){
                dp[i % 2][j] = dp[i % 2][j - 1] + 1;
            }
            else if(!j){
                dp[i % 2][j] = dp[(i - 1) % 2][j] + 1;
            }
            else if(u[i - 1] == v[j - 1]){
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
            }
            else{
                dp[i % 2][j] = min(dp[(i - 1) % 2][j - 1], min(dp[(i - 1) % 2][j], dp[i % 2][j - 1])) + 1;
            }
        }
    }
    cout << dp[lon1 % 2][lon2];
 
    return 0;
}