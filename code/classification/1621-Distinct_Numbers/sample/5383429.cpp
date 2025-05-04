#include "bits/stdc++.h"
using namespace std;
const int N = 1e9, inf = INT_MAX;
#define fastik ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first
#define ss second
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
void solvemes(){ fastik;
    ll n, m; cin >> n >> m;
    vector<string> d(m);
    vector<char> v(m);
    vector<bool> res(m, false);
    for(ll i = 0; i < m; i++) cin >> d[i] >> v[i];
    while(true){
        bool chek = false;
        for(ll i = 0; i < n; i++){
            if(chek) break;
            for(ll val = 0; val <= 1; val++){
                if(chek) break;
                for(ll j = 0; j <= 1; j++){
                    if(chek) break;
                    bool cur = true;
                    bool ans = false;
                    for(ll tc = 0; tc < m; tc++){
                        if(res[tc]) continue;
                        if(d[tc][i] == '0' + val){
                            ans = true;
                            if(v[tc] != '0' + j){
                                cur = false;
                            }
                        }
                    }
                    if(cur && ans){
                        chek = true;
                        for(ll ti = 0; ti < m; ti++){
                            if(res[ti]) continue;
                            if(d[ti][i] == '0' + val){
                                res[ti] = true;
                            }
                        }
                    }
                }
            }
        } if(!chek) break;
    }
    bool ok = true;
    for(ll i = 0; i < m; i++){
        if(res[i] == false) ok = false;
    }
    if(ok) cout << "OK";
    else cout << "LIE";
}
void solve(){ fastik;
    ll n; cin >> n;
    vector<ll> d(n);
    for(ll i = 0; i < n; i++) cin >> d[i];
    set<ll> res;
    for(ll i = 0; i < n; i++) res.insert(d[i]);
    cout << res.size();
}
signed main (){ fastik;
    ll test = 1; //cin >> test;
    while(test--) solve(), cout << '\n';
    cin.get();
    return 0;
}
//  - 32 !- 33 "- 34 #- 35 $- 36 %- 37 &- 38 '- 39 (- 40 )- 41 *- 42 +- 43 ,- 44 -- 45 .- 46 /- 47 
// 0- 48 1- 49 2- 50 3- 51 4- 52 5- 53 6- 54 7- 55 8- 56 9- 57 :- 58 ;- 59 <- 60 =- 61 >- 62 ?- 63 
// @- 64 A- 65 B- 66 C- 67 D- 68 E- 69 F- 70 G- 71 H- 72 I- 73 J- 74 K- 75 L- 76 M- 77 N- 78 O- 79 
// P- 80 Q- 81 R- 82 S- 83 T- 84 U- 85 V- 86 W- 87 X- 88 Y- 89 Z- 90 [- 91 \- 92 ]- 93 ^- 94 _- 95 
// `- 96 a- 97 b- 98 c- 99 d-100 e-101 f-102 g-103 h-104 i-105 j-106 k-107 l-108 m-109 n-110 o-111 
// p-112 q-113 r-114 s-115 t-116 u-117 v-118 w-119 x-120 y-121 z-122 {-123 |-124 }-125 ~-126 -127 
