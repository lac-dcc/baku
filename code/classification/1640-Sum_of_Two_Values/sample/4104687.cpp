#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, rp, lp;
    cin >> n >> m;
    vector <int> v(n);
    vector <int> t(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
        t[i] = v[i];
    }
    sort (t.begin() , t.end());
    lp = 0;
    rp = t.size()-1;
    int sum = -1;
    int l, r;
    while (lp < rp)
    {
        sum = t[lp] + t[rp];
        if (sum > m)
        {
            rp--;
        }
        else if (sum < m)
        {
            lp++;
        }
        else if (sum == m)
        {
            l = lp;
            r = rp;
            break;
        }
    }
    int x, y;
    if (sum == m)
    {
        for (int i = 0 ; i < n ; i++)
        {
            if (t[l] == v[i] )
            {
               x= i+1;
               break;
            }
        }
        for (int i = 0 ; i < n ; i++)
        {
            if (t[r] == v[i] && i != x-1)
            {
                y = i+1;
                break;
            }
        }
        if (x > y )
        {
            cout << y << " " << x;
        }
        else 
        {
            cout << x << " " << y;
        }
    }   
    else
    {
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}
