#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define indexed_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define all(x) x.begin(),x.end()
 
int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cout.precision(0);
//    cout<<fixed;
 
#ifdef LOCAL
    freopen("in","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
 
    int cp;
    cin>>cp;
 
    unordered_map<int, int> acp;
    set<int> events;
 
    while(cp--)
    {
        int in, out;
        cin>>in>>out;
        events.insert(in);
        events.insert(out);
        acp[in]++;
        acp[out]--;
    }
    long long people=0, maxp=0;
    for(auto v: events)
    {
        people+=acp[v];
        maxp=max(people, maxp);
    }
 
    cout<<maxp;
    return 0;
}
/**
 
**/
