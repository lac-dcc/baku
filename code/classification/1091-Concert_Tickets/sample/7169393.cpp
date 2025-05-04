#include<vector>
#include<iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
 
    // int n,m;
    // cin>>n>>m;
    // vector<int> tik(n),cus(m);
    // for(int i=0;i<n;i++)
    //     cin>>tik[i];
 
    // for(int i=0;i<m;i++)
    //     cin>>cus[i];
 
    // sort(tik.begin(),tik.end());
    // vector<int> v(n,false);
 
    // for(int i=0;i<m;i++)
    // {
    //     int ind=upper_bound(tik.begin(),tik.end(),cus[i])-tik.begin();
    //     int ind1=lower_bound(tik.begin(),tik.end(),cus[i])-tik.begin();
 
    //     if(abs(ind-ind1)>1)
    //     {
    //         if(cus[i]>=tik[ind1] && v[ind1]==false && ind<n)
    //         {
    //             cout<<tik[ind]<<endl;
    //             tik[ind1]--;
    //             v[ind1]=true;
                
    //             continue;
    //         }
    //     }
    //     // cout<<ind<<endl;
    //     bool flag=false;
    //     while(ind>=0 && flag==false)
    //     {
    //         if(cus[i]>=tik[ind] && v[ind] ==false && ind<n)
    //         {
    //             v[ind]=true;
    //             cout<<tik[ind]<<endl;
    //             ind=-1;
    //             flag =true;
    //             continue;
 
    //         }
    //         ind--;
    //     }
    //     if(flag ==false)
    //     cout<<-1<<endl;;
    // }
 
    int n,m;
    multiset<int> ms;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ms.insert(x);
    }
    vector<int> cus(m);
    for(int i=0;i<m;i++)
    {
        cin>>cus[i];
        
        auto temp=ms.lower_bound(cus[i]);
        // if(temp==ms.begin())
        // {
        //     cout<<-1;
        // }
        // else{
        //     temp--
        // }
        if(temp!=ms.end() && (*temp==cus[i]))
        {
            cout<<*temp<<endl;
            ms.erase(temp);
        }
        else if(temp!=ms.begin())
        {
            temp--;
            cout<<*temp<<endl;
            ms.erase(temp);
        }
        else{
            cout<<-1<<endl;
        }
    }
    
 
 
 
 
 
 
 
    return 0;
}
