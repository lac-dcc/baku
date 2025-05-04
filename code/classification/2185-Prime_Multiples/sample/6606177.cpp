#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool isOverflow(unsigned long long a, unsigned long long b, unsigned long long batas) {
    unsigned long long x = a * b % batas;
    return x / a != b;
}
vector <unsigned long long> arr;
vector <unsigned long long> subArray;
unsigned long long prefixKali = 1;
unsigned long long batas;
unsigned long long result = 0;
void allSubsets(unsigned long long index, unsigned long long plus)
{
    for (unsigned long long i = index; i < arr.size(); i++) {
        if (isOverflow(prefixKali, arr[i], batas+1)) break;
        prefixKali *= arr[i];
        result += plus * (batas / prefixKali); 
        allSubsets(i + 1, -plus);
        prefixKali /= arr[i];
    }
    return;
}
int main() {
    int k;
    cin >> batas >> k;
    for (int i = 0; i < k; i++)
    {
        unsigned long long input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    allSubsets(0, 1);
    cout << result << endl;
    
    return 0;
}