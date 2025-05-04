#include <iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int n, x;
vector<int> v1;
vector<int> v2;
 
int cost[1000001];
int ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n;i++){
        int a; cin>>a;
        v1.push_back(a);
    }
    for (int i = 0; i < n;i++){
        int b; cin>>b;
        v2.push_back(b);
    }
        for (int i = 0; i < n;i++){
            int curCost = v1[i];
            int curPage = v2[i];
            for (int j = x; j >= 0;j--){
                if(j-curCost>0){
                    if(cost[j-curCost]!=0 && cost[j-curCost]+curPage>cost[j]){
                        cost[j] = cost[j - curCost] + curPage;
                    }
                }
            }
            if(cost[curCost]<curPage){
                cost[curCost] = curPage;
            }
    }
    
    for (int i = 0; i <= x;i++){
        ans = max(ans, cost[i]);
    }
    cout << ans << '\n';
}