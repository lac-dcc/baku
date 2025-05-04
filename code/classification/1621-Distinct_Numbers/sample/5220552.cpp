#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include <stdlib.h>
#define ll long long
#define pf push_front
#define pb push_back
using namespace std;
const int INF=1e9+7;
const int N=1e5+7;
 
int main(){
    int t;
    cin>>t;
    set<int> s;
    while(t--){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
 
    return 0;
}