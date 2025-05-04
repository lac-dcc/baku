#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
long long cnt=0; int s, a, b, v1[25], v2[25];
void dfs(int x, int sum){
    if(sum > s)
        return;
    if(x == a){
        v.push_back(sum);
        return;
    }
    dfs(x+1, sum);
    dfs(x+1, sum+v1[x+1]);
}
void ans(int x, int sum){
    if(sum > s)
        return;
    if(x == b){
        int p1 = lower_bound(v.begin(), v.end(), s-sum) - v.begin();
        int p2 = upper_bound(v.begin(), v.end(), s-sum) - v.begin();
        cnt+=(p2 - p1);
        return;
    }
    ans(x+1, sum);
    ans(x+1, sum+v2[x+1]);
}
int main()
{
    int n;
    cin>>n>>s;
    for(int i=0; i<n/2; i++)
        cin>>v1[i];
    n++;
    for(int i=0; i<n/2; i++)
        cin>>v2[i];
    a = (n-1)/2, b = n/2;
    dfs(-1, 0);
    sort(v.begin(), v.end());
    ans(-1, 0);
    cout<<cnt/4;
    return 0;
}
