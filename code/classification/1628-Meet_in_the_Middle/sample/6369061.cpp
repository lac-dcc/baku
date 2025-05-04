#include <bits/stdc++.h>
#define endl '\n'
 
using namespace std;
long long n,x;
long long a[64];
void read()
{
    cin>>n>>x;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
}
vector<long long> v1,v2;
void rec1(long long i,long long curr)
{
    if(i==n/2+1)
    {
        v1.push_back(curr);
        return;
    }
    rec1(i+1,curr+a[i]);
    rec1(i+1,curr);
}
void rec2(long long i,long long curr)
{
    if(i==n+1)
    {
        v2.push_back(curr);
        return;
    }
    rec2(i+1,curr);
    rec2(i+1,curr+a[i]);
}
long long cnt;
void solve()
{
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(long long i=0;i<v1.size();i++)
    {
        long long sum=x-v1[i];
        if(sum<0)continue;
        long long ansl=-1,ansr=-1;
        long long l=0,r=v2.size()-1;
        while(l<=r)
        {
            long long m=(l+r)/2;
            if(v2[m]<sum)
            {
                ansl=m;
                l=m+1;
            }
            else r=m-1;
        }
        l=0,r=v2.size()-1;
        while(l<=r)
        {
            long long m=(l+r)/2;
            if(v2[m]>sum)
            {
                ansr=m;
                r=m-1;
            }
            else l=m+1;
        }
        if(ansl!=-1&&ansr!=-1)
            cnt+=ansr-ansl-1;
        else if(ansl!=-1)
            cnt+=v2.size()-ansl-1;
        else if(ansr!=-1)
            cnt+=ansr;
    }
    cout<<cnt<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	read();
	rec1(1,0);
	rec2(n/2+1,0);
	solve();
    return 0;
}
