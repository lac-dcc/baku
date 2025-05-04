#define ll long long
#define ull unsigned ll
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pii pair<int, int>
#define tiil tuple <int, int, ll>
#define tlii tuple <ll, int, int>
#define INF numeric_limits<ll>::max()/2
#define intINF numeric_limits<int>::max()/2
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int books;
    cin>>books;
    int xprice;
    cin>>xprice;
    vector<int> prices (books);
    vector<int> pages (books);
    for(int i = 0; i < books; i++)
    {
        cin>>prices[i];
    }
    for(int i = 0; i < books; i++)
    {
        cin>>pages[i];
    }
 
    vector<int> dp(xprice+1, -1);
    dp[0] = 0;
    for(int i = 0; i < books; i++)
    {
        for(int j = xprice-prices[i]; j >= 0; j--)
        {
            if(dp[j] != -1 && dp[j]+pages[i] > dp[j+prices[i]])
            {
                dp[j+prices[i]] = dp[j]+pages[i];
            }
        }
    }
 
    cout<<*max_element(dp.begin(), dp.end())<<endl;
 
    return 0;
}
