#include <bits/stdc++.h>
using namespace std;
 
#define M1 1000000007
#define pb push_back
#define ppb pop_back
#define ll long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef unordered_set<int> unsi;
 
int main()
{   
    int n;
    cin >> n;
 
    int arr[n];
 
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
 
    sort(arr,arr+n);
 
    int prev = arr[0];
 
    ll ans = 1;
 
    for(int i=1;i<n;i++)
    {
        if(prev != arr[i])
        {
            ans++;
            prev = arr[i];
        }
    }
 
    cout  << ans << endl;
}
