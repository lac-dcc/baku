/*
02  Apartments
LANG: C++
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 2*100000
#define MAX_M 2*100000
#define MAX_K 1000000000
#define MAX_A 1000000000
#define MAX_B 1000000000
 
int main()
{
    int nApplicant, nApart, maxDiff;
    cin >> nApplicant >> nApart >> maxDiff;
 
    long desired[nApplicant];
    long aptSize[nApart];
 
    //bool occupied[nApart] = {false};
    vector<bool> occupied(nApart, false);
    int room_count=0;
 
    for (int idx=0; idx<nApplicant; ++idx)
    {
        cin >> desired[idx];
    }
 
    for (int idx=0; idx<nApart ; ++idx)
    {
        cin >> aptSize[idx];
    }
 
    sort(aptSize, aptSize+nApart);
    sort(desired, desired+nApplicant);
 
    int idx=0, id=0;
    while(idx < nApplicant && id < nApart)
    {
        if (desired[idx]+maxDiff < aptSize[id]) idx++;
        else if (desired[idx]-maxDiff > aptSize[id]) id++;
        else {idx++; id++; room_count++;}
    }
 
    cout << room_count << endl;
}
