#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    int num;
    int ind;
};
 
bool comp(struct node a, node b)
{
    return (a.num <= b.num);
}
 
int main()
{
    int n,x;
    cin>>n>>x;
    struct node a[n];
    for (int i = 0 ; i < n; i++)
    {
        cin>>a[i].num;
        a[i].ind = i+1;
    }
    sort(a, a + n, comp);
    for(int i = 0 ; i < n - 3; i++)
    {
        for (int j = i+1; j < n-2;j++)
        {
            int p = j+1;
            int q = n-1;
            while (p<q)
            {
                if (a[i].num + a[j].num + a[p].num + a[q].num == x)
                {
                    cout<<a[i].ind<<" "<<a[j].ind<<" "<<a[p].ind<<" "<<a[q].ind<<endl;
                    return 0;
                }
                else if (a[i].num + a[j].num + a[p].num + a[q].num > x)
                {
                    q--;
                }
                else
                {
                    p++;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
