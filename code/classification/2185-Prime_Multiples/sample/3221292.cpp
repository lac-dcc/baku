/*
 
 
weak        weak  we      ak   we  akwea        weak  we
  weak    weak    we      ak   weak    weak    we  ak we
    weakweak      we      ak   wea       ak   we    akwe
      wea         we      ak   we        ak   we    akwe
      wea         we      ak   we        ak   we    akwe
      wea          eak  weak   we        ak    we  ak we
      wea            wea  ak   we        ak     weak  we
                                                      we
we      ak     wea  ak       weak                     we
 we    ak    wea  weak     wea  eak                   we
  we  ak    we      ak   wea      wea         we      we
   weak     we      ak   we        we         we      we
    we      we      ak   we        we         we      we
   we        wea  weak    wea    wea          weak  weak
weak           wea  akw      weak                weak
 
 
*/
//#define _GLIBCXX_DEBUG //is only used when couldn't find bug
using namespace std;
#pragma GCC optimize ("Ofast")
//headers
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <utility>
#include <bitset>
#include <set>
#include <string>
#include <stack>
#include <iomanip>
#include <map>
#include <memory.h>
#include <deque>
#include <time.h>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
 
//defines
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<LL>> vvl;
#define pb push_back
#define F first
#define S second
#define mid (LB+RB)/2
#define mkp make_pair
 
//iterators
#define iter(x) x.begin(),x.end()
#define aiter(a,n) a,a+n
 
//loops
#define REP(n) for (int ___=n > 0 ? n : 0;___--;)
#define REP0(i,n) for (int i=0,___=n;i<___;++i)
#define REP1(i,n) for (int i=1,___=n;i<=___;++i)
#define MEM(e,val) memset (e,val,sizeof(e))
 
/*
When he said Super Idol的笑容都没你的甜八月正午的阳光都没你耀眼热爱 105 °C的你滴滴清纯的蒸馏水你不知你有多可爱跌倒后会傻笑着再站起你从来都不轻言失败对梦想的执着一直不曾改很安心 当你对我说不怕有我在放着让我来勇敢追自己的梦想那坚定的模样,
I really felt that.
 
 
every one is so dian except me
still too weak 咩噗
*/
 
//IO
#include <cstdio>
#include <iostream>
#include <fstream>
#define want_to_be_more_dian ios_base::sync_with_stdio(false),cin.tie(0);
 
//pbds
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
//tree <pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>;
*/
 
//constants
#include <climits>
const int maxn = 1e5,mod = 0;
const long long inf = 0;
const double eps = 0;
 
//workspace
 
LL mtp[1 << 20];
 
inline void solve(){
    int n;
	LL k;
	LL p[20];
 
    cin >> k >> n;
	REP0(i,n) cin >> p[i];
	LL ans = 0;
	mtp[0] = 1;
	for (int mask=1;mask<1<<n;++mask){
		if (mtp[mask ^ (1 << __lg(mask))] > k / p[__lg(mask)]) mtp[mask] = k+1;
		else mtp[mask] = mtp[mask ^ (1 << __lg(mask))] * p[__lg(mask)];
 
		ans += (__builtin_popcount(mask) & 1 ? 1 : -1) * (k / mtp[mask]);
	}
	cout << ans;
}
 
signed main(){
    want_to_be_more_dian
    //int t,i=1; for (int ;cin;)//use in multi-testcases and end in EOF problems
    //int t,i=1; for (cin >> t;i<=t;++i)//use in multi-testcases problems
    //cout << "Case #" << i << ": ",//use in Google, FB competitions
    solve();//always used
    return 0;
}