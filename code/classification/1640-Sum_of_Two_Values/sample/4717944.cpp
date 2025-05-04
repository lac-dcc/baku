/* ****************** Created By Ansh Varshney ;) ******************  */
#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define popcount(x)     __builtin_popcountll(x)
#define llmax LONG_LONG_MAX
#define llmin LONG_LONG_MIN
#define endl "\n"
#define trace_stream cerr
#define COLOR_START ""
#define COLOR_END ""
#define trace(args...)                                                         \
{                                                                          \
    trace_stream << COLOR_START << __LINE__ << "> " << COLOR_END;          \
    string arg_string = #args;                                             \
    vector<string> arg_list = _parse_args(arg_string);                     \
    _err(arg_list.begin(), args);                                          \
}
const vector<pair<char, char>> _BRACKETS{{'(', ')'}, {'{', '}'}, {'[', ']'}};
vector<string> _parse_args(string &arg_string) {
    vector<string> res;
    int stack_size = 0;
    int last = 0, len = 0;
    for (int i = 0; i < arg_string.size(); i++) {
        if (arg_string[i] == ',' && stack_size == 0) {
            res.push_back(arg_string.substr(last, len));
            last = i + 1;
            len = 0;
        } else {
            for (auto bp : _BRACKETS) {
                if (bp.first == arg_string[i])
                    stack_size++;
                else if (bp.second == arg_string[i])
                    stack_size--;
            }
            if (len || arg_string[i] != ' ')
                len++;
            else
                last = i + 1;
        }
    }
    if (len > 0)
        res.push_back(arg_string.substr(last, len));
    return res;
}
 
template <typename T> void _err(vector<string>::iterator it, T a) {
    trace_stream << *it << ':' << a << endl;
}
 
template <typename T, typename... Args>
void _err(vector<string>::iterator it, T a, Args... args) {
    trace_stream << *it << ':' << a << " | ";
    _err(++it, args...);
}
 
template <typename T> void _err(istream_iterator<string> it, T a) {
    cout << *it << ':' << a << endl;
}
template <typename T, typename... Args>
void _err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << ':' << a << " | ";
    _err(++it, args...);
}
 
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os,
                                  Container const &c) {
    os << "{";
    if (!c.empty()) {
        os << *c.begin();
        for (auto i = ++c.begin(); i != c.end(); i++)
            os << ", " << *i;
    }
    return os << "}";
}
 
void init()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif 
}
 
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(a[i].first+a[j].first==x)
        {
            cout<<a[i].second<<" "<<a[j].second<<endl;
            return;
        }
        else if(a[i].first+a[j].first>x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout<<"IMPOSSIBLE";
}
 
int main()
{
    init();
    // int t;
    // cin>>t;
    // while(t--)
    solve();
    return 0;
}