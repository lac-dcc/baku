#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
#define REP(i,a,b) for(int i=a;i<b;i++);
 
int main(){
        ll n,ct=0;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++){
            if(a[i]!=a[i+1])
            ct++;
        }
        cout<<ct+1;
}