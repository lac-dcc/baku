#include <iostream>
#include <vector>
#include <array>
#include <math.h>
using namespace std;
 
void weird();
void missing();
void rep();
void increase_arr();
void perm();
void spiral();
 
int main()
{
    spiral();
    return 0;
}
 
void weird()
{
    size_t n;
    cin >> n;
    while(n != 1)
    {
        cout << n << ' ';
        if(n & 1) // odd
        {
            n *= 3;
            n++;
        }
        else
        {
            n /= 2;
        }
    }
    cout << '1';
}
 
void missing()
{
    size_t n;
    cin >> n;
    size_t true_sum = 0;
    for (int i = 1; i <= n; ++i) {
        true_sum += i;
    }
    size_t sum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int in;
        cin >> in;
        sum += in;
    }
    cout << true_sum - sum;
}
 
void rep()
{
    string line;
    getline(cin, line);
 
    size_t longest_substr = 0;
    for (int i = 0; i < line.size(); ++i)
    {
        size_t current_substr_size = 0;
        char c = line[i];
        for (int j = i; j < line.size(); ++j, i++)
        {
            if(line[j] == c)
                current_substr_size++;
            else
                break;
        }
        i--;
        if(current_substr_size > longest_substr) longest_substr = current_substr_size;
    }
    cout << longest_substr;
}
 
void increase_arr()
{
    size_t n;
    cin >> n;
 
    size_t moves = 0;
    size_t* arr = new size_t[n];
    cin >> arr[0];
    for (int i = 1; i < n; ++i)
    {
        cin >> arr[i];
        if(arr[i] < arr[i-1])
        {
            size_t diff = arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
            moves += diff;
        }
    }
    cout << moves;
}
 
void perm()
{
    size_t n;
    cin >> n;
    if(n == 3 || n == 2)
    {
        cout << "NO SOLUTION";
        return;
    }
    size_t* arr = new size_t [n];
    for (int j = 2; j <= n; j+=2)
    {
        cout << j << ' ';
    }
 
    for (int i = 1; i <= n; i+=2)
    {
        cout << i << ' ';
    }
}
 
void spiral()
{
    int t;
    cin >> t;
 
    while(t--)
    {
        size_t x, y;
        cin >> y >> x;
 
        size_t max = x > y ? x : y;
        size_t diagonal_Val = max * max - (max - 1);
        bool max_odd = max & 1;
        if(max_odd)
        {
            while(x++ < max)
            {
                diagonal_Val--;
            }
            while(y++ < max)
            {
                diagonal_Val++;
            }
        }
        else
        {
            while(x++ < max)
            {
                diagonal_Val++;
            }
            while(y++ < max)
            {
                diagonal_Val--;
            }
        }
        cout << diagonal_Val << '\n';
    }
}
