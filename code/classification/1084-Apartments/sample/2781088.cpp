#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<set>
#include<climits>
using namespace std;
#define ll long long 
 
set<string> st;
int vis[7][7];
int cnt=0;
 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char d[4] = {'U','D','L','R'};
 
 
int main() {
    int n,m,k;
    cin>>n>>m>>k;
 
    vector<int> want(n);
 
    for(int i=0;i<n;i++)
    cin>>want[i];
 
    vector<int> giv(m);
 
    for(int i=0;i<m;i++)
    cin>>giv[i];
 
    sort(want.begin(),want.end());
    sort(giv.begin(),giv.end());
 
    //
    int i=0,j=0;
 
    while(i<n && j<m) {
        //
        int a = want[i]-k;
        int b = want[i]+k;
 
        if(giv[j]<a)
        j++;
 
        else if(giv[j]>b)
        i++;
 
        else
        {
            cnt++;
            i++;
            j++;
        }
    }
 
    cout<<cnt<<"\n";
    
    return 0;
}