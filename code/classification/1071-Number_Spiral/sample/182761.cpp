#include<bits/stdc++.h>
#include<stdio.h> //per fare input output con scanf and printf
#include<stdlib.h> //per fare qsort e bsearch
#include<string.h> // per fare strcpy(sarrivo, spartenza) strcat(str, aggiungo) strcmp(a,b) che da 0 se sono uguali
#include<math.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
 
using namespace std;
 
#define REP(n) for(int i = 0; i < (n); i++)
#define endl '\n'
#define ld long double
#define ll long long int
#define vi vector <int> 
#define pi pair <int, int>
#define make(type, x) type (x); cin>>(x)
#define print(x) cout<<x<<endl
#define binary(v, el) binary_search((v).begin(), (v).end(), (el))
 
int main(){
    ll n,x,y; cin >> n;
    for (ll i=0; i<n; i++){
        cin >> y >> x;
        if (x==y) cout << y*y-y+1 << endl;
        else if (y>x && y%2 == 0) cout << y*y-x+1 << endl;
        else if (y>x && y%2 == 1) cout << (y-1)*(y-1)+x << endl;
        else if (y<x && x%2 == 1) cout << x*x-y+1 << endl;
        else cout << (x-1)*(x-1)+y << endl;
    }
}