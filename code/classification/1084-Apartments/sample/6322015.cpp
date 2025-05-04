#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, m, k, ib = 0, compteur = 0;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(int loop = 0; loop < n; loop++)
        cin >> a[loop];
    for(int loop = 0; loop < m; loop++)
        cin >> b[loop];
    sort(a, a + n);
    sort(b, b + m);
    for(int loop = 0; loop < n; loop++)
    {
        if(ib == m)
            break;
        if(b[ib] < a[loop] - k)
            if(ib < m)
                while(b[ib] < a[loop] - k)
                    ib++;
        if(ib < m)
            if(b[ib] <= a[loop] + k and b[ib] >= a[loop] - k)
            {
                compteur++;
                ib++;
            }
    }
    cout << compteur;
}
