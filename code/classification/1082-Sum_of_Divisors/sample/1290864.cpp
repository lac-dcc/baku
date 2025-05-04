#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
long long s;
long long a;
#define mod 1000000007
long long sum(long long a,long long b){
    long long p = a+b;
    long long t = b-a+1;
    if (p%2==0) p/=2; else t/=2;
    return ((p%mod)*(t%mod))%mod;
}
int main(){
    cin>>a;
    long long lower = sqrt(a);
    for (long long i = 1;i<=lower;i++){
        s = (s + (((a/i)%mod)*i%mod))%mod;
    }
    long long upper = a;
    long long mid = 2;
    while (upper>lower){
        long long point = a/mid+1;
        if (point<=lower) point = lower + 1;
        s = (s + ((sum(point,upper) * (mid-1))%mod))%mod;
        upper = point - 1;
        mid++;
    }
    cout<<s;
}
