#include <iostream> //Provides input and output stream functionalities, including cin and cout for console input/output
#include <cmath> //Contains mathematical functions like sqrt(), sin(), cos(), etc
#include <vector> //Implements dynamic arrays, similar to lists in other programming languages
#include <string> //Used for string manipulation operations
#include <algorithm> //Includes various algorithms like sorting, searching, and more.
#include <queue> //Provides functionality for implementing queues
#include <stack> // Used for stack data structure operations
#include <map> //Implements associative arrays (key-value pairs)
#include <set> //Implements sets, which are collections of unique elements
#include <unordered_map> //Implements hash tables for fast key-value lookups
#include <unordered_set> //Implements sets with fast lookup using hash tables
#include <fstream> //Used for file input/output operations
#include <iomanip> //Provides formatting options for input/output
#include <ctime> //Contains functions related to date and time
#include <cstdlib> //Includes functions related to memory allocation, random numbers, etc
#include <cstring> //Provides functions for string manipulation and memory operations
#include <stdexcept> //Contains standard exception classes
#include <cstddef> //Defines various types and macros for working with pointers and memory addresses
#include <iterator> //Includes various iterator-related classes and functions
#include <functional> //Provides tools for creating and using function objects
 
using namespace std;
 
int main ()
{
    int n;
    int e;
    int x;
    int nb;
    map<int, int> mymap;
    cin >> n >> e;
    for(int i = 1; i <= n; i++)
    {
        cin >> nb;
        x = e - nb;
        if (mymap[x] != 0 && i != mymap[x])
        {
            cout << mymap[x] << ' ' << i << '\n';
            return (0);
        }
        else
        {
            mymap[nb] = i;
        }
    }
    cout << "IMPOSSIBLE\n";
}