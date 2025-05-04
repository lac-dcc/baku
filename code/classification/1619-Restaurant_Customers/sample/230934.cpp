/*
05 Restaurant Customers
LANG: C++
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first < j.first;
};
 
int main()
{
    int n_Customer;
    cin >> n_Customer;
 
    vector <long> start_t;
    vector <long> end_t;
 
    for(int idx=0; idx < n_Customer; ++idx)
    {
        int start_time =0, end_time =0;
        cin >> start_time >> end_time ;
        start_t.push_back(start_time);
        end_t.push_back(end_time);
    }
 
    sort(start_t.begin(), start_t.end());
    sort(end_t.begin(), end_t.end());
 
 
    int c_customer=0;
    int i=0, j=0;
    int ct_now=0;
    while( i< n_Customer )
    {
        if (start_t[i] < end_t[j])
        {
            ct_now++;
            i++;
        }
        else
        {
            j++;
            ct_now--;
        }
        c_customer = max(c_customer, ct_now);
    }
 
    cout << c_customer << endl;
}
