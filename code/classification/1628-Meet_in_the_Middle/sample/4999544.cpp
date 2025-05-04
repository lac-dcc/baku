#include <iostream>
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
#define N 20
int v[2*N];
vector<int> vx, vy;
int prex[(1 << N) + 1];
int prey[(1 << N) + 1];
int gx;
 
void calcsubarrayx(int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        int s = 0;
        for (int j=n-1; j>=0; j--)
            if (i & (1<<j))
            {
                s = v[j+c] + prex[i ^ (1 << j)];
                break;
            }
        prex[i] = s;
        if (s > gx)
            continue;
        vx.push_back(s);
    }
}
 
void calcsubarrayy(int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        int s = 0;
        for (int j=n-1; j >= 0; j--)
            if (i & (1<<j))
            {
                s = v[j+c] + prey[i ^ (1 << j)];
                break;
            }
        
        prey[i] = s;
        if (s > gx)
            continue;
        vy.push_back(s);
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
   
    cin>>n>>gx;
   
    vx.reserve((1 << N));
    vy.reserve((1 << N));
   
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
       
    int ans=0;
 
	int n1=(n>>1);
   
    calcsubarrayx(n1, 0);
    calcsubarrayy(n-n1, n1);
    
    sort(vy.begin(), vy.end());
    
    for (int i: vx)
    {
        auto p = equal_range(vy.begin(), vy.end(), gx-i);
        ans += p.second - p.first;
    }
    
    cout<<ans;
}
