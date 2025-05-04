/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    set<int> st;
    while(t--)
    {
        int a;
        cin>>a;
        st.insert(a);
    }
    cout<<st.size();
    return 0;
}
