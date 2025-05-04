/*
 * Filename: c:\Coding\C++\graph\kiem_tra_do_thi_2_phia.cpp
 * Path: c:\Coding\C++\graph
 * Created Date: Tuesday, September 13th 2022, 10:45:00 am
 * Author: Qu?c Ho ng
 *
 * Copyright (c) 2022 Your Company
 */
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define name "text"
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;
 
#define fillchar(a, x) memset(a, x, sizeof(a))
#define FOR(i, l, r) for (int i = l; i <= r; ++i)
#define FOD(i, r, l) for (int i = r; i >= l; --i)
#define faster                          \
      ios_base::sync_with_stdio(false); \
      cin.tie(NULL);                    \
      cout.tie(NULL);
 
const int nmax = 100005;
int n, m;
int color[nmax]; //  mảng color có 2 giá trị màu : 0 --> red; 1 --> blue;
vector<int> adj[nmax];
 
void inp()
{
      cin >> n >> m;
      FOR(i, 1, m)
      {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
      }
      fillchar(color, -1); // fillchar màu ban đầu là -1;
}
 
bool bfs(int u)
{
      queue<int> q;
      color[u] = 0;
      q.push(u);
      while (!q.empty())
      {
            int n1 = q.front();
            q.pop();
            for (int n2 : adj[n1])
            {
                  if (color[n2] == -1)
                  {
                        color[n2] = (color[n1] == 0) ? 1 : 0;
                        q.push(n2);
                  }
                  else if (color[n2] == color[n1])
                  {
                        return false;
                  }
            }
      }
      return true;
}
 
int main()
{
      faster;
      // freopen(name ".inp", "r", stdin);
      // freopen(name ".out", "w", stdout);
 
      inp();
 
      // Kiểm tra tính liên thông của đồ thị nếu các thành phần liên thông trên đồ thị là 2 phái thì đồ thị sẽ là đồ thị 2 phía còn không thì không phải
      bool check = true;
      FOR(i, 1, n)
      {
            if (color[i] == -1)
            {
                  if (!bfs(i))
                  {
                        check = false;
                        break;
                  }
            }
      }
      if (check)
      {
            // cout << "YES\n";
            FOR(i, 1, n)
            {
                  cout << color[i] + 1 << ' ';
            }
      }
      else
            cout << "IMPOSSIBLE\n";
      return 0;
}
