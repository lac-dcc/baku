#include <iostream>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
 
    int t;
    long long x, y;
    cin >> t;
 
    for (int i = 0; i < t; ++i)
    {
        cin >> y >> x;
        if (x > y)
            if (x % 2 != 0)
                cout << x * x - y + 1 << '\n';
            else
                cout << (x - 1) * (x - 1) + y << '\n';
        else
            if (y % 2 == 0)
                cout << y * y - x + 1 << '\n';
            else
                cout << (y - 1) * (y - 1) + x << '\n';
    }
 
    return 0;
}