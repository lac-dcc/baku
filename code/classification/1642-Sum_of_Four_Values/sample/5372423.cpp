/********   All Required Header Files ********/
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <typeinfo>
#include <fstream>
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
bool comparator(pair<int64, int64> a, pair<int64, int64> b){
    return (a.first<b.first ? true : false);
}
 
class cmp_multiset {
public:
    // Comparator function
    bool operator()(pair<int32, int32> a,pair<int32, int32> b) const
    {
 
        if(a.first<b.first){
        return true;
    } else {
        return false;
    }
    }
};
 
class comparator_class {
public:
    // Comparator function
    bool operator()(array<int64, 2> a, array<int64, 2> b) const
    {
 
        // There can be any condition
        // implemented as per the need
        // of the problem statement
        if(a[0]<b[0]){
            return true;
        } else if(a[0]==b[0] && a[1]<b[1]){
            return true;
        }
        return false;
    }
};
 
/*for ordered set*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<array<int64, 2>, null_type,comparator_class, rb_tree_tag,tree_order_statistics_node_update>
// for ordered set
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int te;
    te=1;
    // cin>>te;
    while(te>0){
        te--;
        int32 n, x;
        cin>>n>>x;
        int64 arr[n];
        for(int32 i=0;i<n;i++){
            cin>>arr[i];
        }
        map<int64, pair<int32, int32>> hm;
        for(int32 i=0;i<n-1;i++){
            for(int32 j=i+1;j<n;j++){
                int64 sum = x - arr[i] - arr[j];
                if(hm.find(sum)!=hm.end()){
                    cout<<i+1<<" "<<j+1<<" "<<hm[sum].first<<" "<<hm[sum].second;
                    return 0;
                }
            }
            for(int32 k=0;k<i;k++){
                hm[arr[i]+arr[k]] = pair<int32, int32>{k+1, i+1};
            }
        }
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
