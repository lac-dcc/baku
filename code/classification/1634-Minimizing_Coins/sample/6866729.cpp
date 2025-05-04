#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int MinCoins(int n, vector<int> &arr, int i, vector<int> &strg)
{
    if(n<0 || i == arr.size())
        return 10000000;
    else if(n == 0)
    {
        return 0;
    }
    if(strg[n] != -1)
        return strg[n];
    int a = MinCoins(n-arr[i], arr, i, strg) + 1;
    int b = MinCoins(n, arr, i+1, strg);
    strg[n] = min(a, b);
    return strg[n];
}
 
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> arr(n);
    for(auto &val : arr)
        cin>>val;
    
    sort(arr.begin(), arr.end());
    vector<int> strg(m+1, -1);
    MinCoins(m, arr, 0, strg);
    if(strg[m] == 10000000)
        cout<<-1;
    else
        cout<<strg[m];
}