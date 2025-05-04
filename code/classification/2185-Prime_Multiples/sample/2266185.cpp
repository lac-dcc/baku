#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <math.h>
#include <unordered_set>
#include <set>
#include <cstring>
#define ll              long long
#define vii             vector<int>
#define vll             vector<ll>
#define mii             map<int, int>
#define mll             map<ll, ll>
#define si              set<int>
#define sl              set<ll>
#define umi             unordered_map<int, int>
#define uml             unordered_map<ll, ll>
#define usi             unordered_set<int>
#define usl             unordered_set<ll>
#define maxpq           priority_queue<int>
#define minpq           priority_queue<int,vii,greater<int>()>
#define pii             pair<int, int>
#define pll             pair<ll, ll>
#define pb              push_back
#define pf              push_front
#define mp              make_pair
#define endl            "\n"
#define desc            greater<int>()
#define F               first
#define S               second
#define mod             1000000007
#define pi              3.141592653589793238
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define FASTI1
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
 
int main() 
{
    FIO 
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(k);
    for (int i =0;i<k;i++) cin>>arr[i];
    ll answer = 0;
    for (ll i = 1;i<1<<k;i++){
        ll current = 1;
        for (int j =0;j<k;j++){
            if (i>>j&1){
                if (current>n/arr[j]){
                    current = n+1;
                    break;
                }
                current *= arr[j];
            }
        }  
        if (setbits(i)%2==1){
            answer += n/current;
        }else{
            answer -= n/current;
        }
    }
    cout<<answer<<endl;
 
  return 0;   
}