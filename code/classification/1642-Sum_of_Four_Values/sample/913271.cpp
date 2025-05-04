#include<iostream>
#include<bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define all(a) a.begin(),a.end()
 
using namespace std;
int N,i,T,sum;
bool diff(const pair<int,int>& p1,const pair<int,int>& p2)
{
    return p1.first!=p2.first && p1.first !=p2.second 
        && p1.second!=p2.first && p1.second !=p2.second;
}
pair<bool,tuple<int,int,int,int>> find_diff(pair<int,int>& p,vector<pair<int,int>>& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        if(diff(p,vec[i]))
            return {true,{p.first,p.second,vec[i].first,vec[i].second}};
    }
    return {false,{-1,-1,-1,-1}};
}
pair<bool,tuple<int,int,int,int>> find_diff(vector<pair<int,int>>& A,vector<pair<int,int>>& vec)
{
    for(int i=0;i<A.size();i++)
    {
        auto val=find_diff(A[i],vec);
        if(val.first)
            return val;
    }
    return {false,{-1,-1,-1,-1}};
}
void solve()
{
    cin>>N>>sum;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin>>A[i];
    map<int,vector<pair<int,int>>> mp;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            mp[A[i]+A[j]].push_back({i+1,j+1});
        }
    }
    for(auto v:mp)
    {
        int s1=v.first;
        int left=sum-s1;
        if(mp.find(left)!=mp.end())
        {
            auto val=find_diff(mp[s1],mp[left]);
            if(val.first)
            {
                vector<int> v={get<0>(val.second),get<1>(val.second),get<2>(val.second),get<3>(val.second)};
                sort(all(v));
                for(int i:v)
                    cout<<i<<" ";
                cout<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
int32_t main()
{
    IOS
    // cin>>T;
    // while(T--)
        solve();
    return 0;
}