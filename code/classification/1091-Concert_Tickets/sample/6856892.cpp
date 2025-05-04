#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define u unsigned
#define F first
#define S second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precision(n) cout<<setprecision(n)<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint);
#define endl '\n'
using namespace std;
//--------------------------------CONSTANTS--------------------------------
//const int N = (2e5)+2;
//--------------------------------FUNCTIONS--------------------------------
 
//--------------------------------FUNCTIONS--------------------------------
int main()
{
    fast;
    int t = 1;
    //cin >> t;
    while(t--)
    {
        //--------------------------------TESTCASES--------------------------------
        int n,m;
        cin>>n>>m;
 
        ll temp;
        multiset<ll> pr;
 
        for(ll i=0; i<n; i++)
        {
            cin>>temp;
            pr.insert(temp);
        }
 
        bool found;
        for(ll i=0; i<m; i++)
        {
            cin>>temp;
            found = false;
            if(pr.size() > 0)
            {
                auto val = pr.lower_bound(temp);
                if(val == pr.end())
                {
                    cout<<*--val<<endl;
                    pr.erase(val);
                    continue;
                }
                if(*val <= temp)
                {
                    found = true;
                }
                else
                {
                    while(val != pr.begin())
                    {
                        val--;
                        if(*val <= temp)
                        {
                            found = true;
                            break;
                        }
                    }
                }
 
                if(found)
                {
                    cout<<*val<<endl;
                    pr.erase(val);
                }
                else cout<<-1<<endl;
            }
            else cout<<-1<<endl;
        }
        //--------------------------------TESTCASES--------------------------------
    }
}
