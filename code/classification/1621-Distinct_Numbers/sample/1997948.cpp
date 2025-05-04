#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
 
    int n;
    cin >> n;
    long long arr[n];
 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
 
    sort(arr , arr+n);
    long long past = arr[0];
    long long present;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        present = arr[i];
        if(present != past){
            count ++;
            past = arr[i];
        }
    }
    cout << count << endl;
    return 0;
}
