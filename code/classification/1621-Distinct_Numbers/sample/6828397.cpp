#include <iostream>
#include <algorithm>
 
using namespace std;
 
long long numbers[10000000];
 
int main()
{
    bool zostaw;
    long long ilosc_liczb, i, l, answer;
    cin >> ilosc_liczb;
    answer=1;
 
    for (i=0; i<ilosc_liczb; ++i){
        cin >> numbers[i];
    }
    sort (numbers, numbers+ilosc_liczb);
    zostaw=true;
    for (i=1; i<ilosc_liczb; ++i){
            if (numbers[i]==numbers[i-1]){
                zostaw=false;
                }
                else
                    {
                    ++answer;
    }
    }
    cout << answer;
}
 
