///HELLO THERE~!
///CODED BY MD SADMAN MEHEDI SIVAN [IUT CSE(SWE)-19]
 
#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define read            freopen("blue.txt","r",stdin);
#define write           freopen("red.txt","w",stdout);
 
using ll=long long;
using ull=unsigned long long;
const double pi = 2*acos(0.0);
 
 
void overlap(vector<pair<long long, long long> > v)
{
 
    long long ans = 0;
    long long count = 0;
    vector<pair<long long, char> > data;
 
    for (long long i = 0; i < v.size(); i++)
    {
 
        data.push_back({ v[i].first, 'x' });
 
        data.push_back({ v[i].second, 'y' });
    }
 
 
    sort(data.begin(), data.end());
 
    for (long long i = 0; i < data.size(); i++)
    {
 
 
        if (data[i].second == 'x')
            count++;
 
        if (data[i].second == 'y')
            count--;
 
 
        ans = max(ans, count);
    }
 
    cout << ans << endl;
}
 
int main()
{
    long long n;
    cin>>n;
 
    vector<pair<long long, long long> > v;
 
   for(ll i=0; i<n; i++)
    {
        long long a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
 
    overlap(v);
 
    return 0;
}
