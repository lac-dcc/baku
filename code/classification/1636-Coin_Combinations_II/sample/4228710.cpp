#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
 
 
using namespace std;
 
 
#define loop(q, j, i) for(int i = q; i < j; i++)
#define bloop(q, j, i) for(int i = q; i >= j; i--)
#define v vector
#define vi v<int>
#define ks size()
#define f1 first
#define s2 second
#define b1 begin()
#define e2 end()
#define add push_back
#define po pop_back
#define in insert
#define del erase
#define ll long long
#define pi pair<int, int>
#define vpi v<pair<int, int>>
#define pll pair<ll, ll>
#define vll v<ll>
#define vpll v<pll>
#define vvll v<vll>
#define vvi v<vi>
#define vvpi v<vpi>
#define str string
#define sp << " "
#define el << "\n"
 
 
const int s_inf = 1e9 + 3;
const ll inf = 2e18;
const ll mod = 1e9 + 7, mod2 = 1e9 + 9;
v<char> AB = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
v<char> ab = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
 
 
int main()
{
    int n, x, ip;
    cin >> n >> x;
    vll pos;
    loop(0, x + 1, i) 
        pos.add(0);   
    pos[0] = 1;
 
    loop(0, n, i) {
        cin >> ip;
        loop(ip, x + 1, j) 
            pos[j] = (pos[j] + pos[j - ip]) % mod;    
    }
 
    cout << pos[x] << "\n";
}
