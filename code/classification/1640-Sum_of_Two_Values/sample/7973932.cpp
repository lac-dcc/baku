#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long n, x;
    vector <long> a;
    vector <long> aSort;
    cin >> n >> x;
    for(long i=0; i<n; ++i){
        long ai;
        cin >> ai;
        a.push_back(ai);
        aSort.push_back(ai);
    }
 
    sort(aSort.begin(), aSort.end());
 
    // two Pointer
    long left = 0;
    long right = a.size()-1;
    long currentSum = 0;
 
    currentSum = aSort[left]+aSort[right];
    while(currentSum != x && left < right){
        if(currentSum < x){
            ++left;
        }else{
            --right;
        }
        currentSum = aSort[left]+aSort[right];
    }
 
    if(left < right){
        long ausgabe1 = -1;
        long ausgabe2 = -1;
//        for(long i=0; i<n; ++i){
//            if(ausgabe1 == -1 && aSort[left]==a[i]){
//                ausgabe1 = i+1;
//            } else if(ausgabe2 == -1 && aSort[right]==a[i]){
//                ausgabe2 = i+1;
//            }
//        }
        for(long i=0; i<n; ++i){
            if(aSort[left]==a[i]){
                ausgabe1 = i+1;
                break;
            }
        }
        for(long i=n-1; i>=0; --i){
            if(aSort[right]==a[i]){
                ausgabe2 = i+1;
                break;
            }
        }
        cout << ausgabe1 << ' ' << ausgabe2;
    }else{
        cout << "IMPOSSIBLE";
    }
 
    return 0;
}
