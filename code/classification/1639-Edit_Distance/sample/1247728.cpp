#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int dist[a.length() + 1][b.length() + 1];
    for(int i = 0; i <= a.length(); i++)
        dist[i][0] = i;
    
    for(int j = 0; j <= b.length(); j++)
        dist[0][j] = j;
    
    for(int i = 1; i <= a.length(); i++)
    {
        for(int j = 1; j <= b.length(); j++)
        {
            dist[i][j] = min({dist[i][j-1] + 1, dist[i-1][j] + 1, dist[i-1][j-1] + (a[i-1] != b[j-1])});
        }
    }
 
    cout << dist[a.length()][b.length()] << '\n';
    return 0;
}
