#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
 
// Counting Rooms
// funny solution using only 1 row at time
using namespace std;
typedef unordered_map<int, int> cmap;
 
inline float getTime()
{
  return (float)clock()/CLOCKS_PER_SEC;
}
 
inline void printTime(const char *pfx)
{
#ifdef TIME
  printf("%s: %f\n", pfx, getTime());
#endif
}
 
struct room_row
{
  int left, end, color;
};
 
struct cr
{
  int N;
  vector<int> row;
  int color_cnt = 0;
  int next_color = 0;
  cr(int n): N(n), row(n, -1)
  {
  }
  inline int get_new_color()
  {
    color_cnt++;
    return ++next_color;
  }
  int get_color(cmap &m, int a, cmap::iterator &ma)
  {
    if ( ma == m.end() ) return a;
    auto next = m.find(ma->second);
    return get_color(m, ma->second, next);
  }
  int get_color(cmap &m, int a)
  {
    auto next = m.find(a);
    if ( next == m.end() ) return a;
    return get_color(m, next->second, next);
  }
  void patch_color(cmap &m, int c, int v)
  {
    int old = m[c];
    m[c] = v;
    auto prev = m.find(old);
    while( prev != m.end() )
    {
      old = prev->second;
      prev->second = v;
      prev = m.find(old);
    }
  }
  int merge_colors(cmap &m, int a, int b)
  {
    if ( a == b ) return a;
    if ( a > b ) swap(a, b);
    auto ma = m.find(a);
    auto mb = m.find(b);
    // if we meet b for first time - add new mapping and dec color_cnt
    if ( ma == m.end() && mb == m.end() )
    {
      color_cnt--;
      m[b] = a;
      return a;
    }
    int ra = get_color(m, a, ma);
    int rb = get_color(m, b, mb);
    if ( ra == rb )
      return ra;
    color_cnt--;
    if ( ra < rb )
    {
      if ( mb == m.end() ) m[b] = ra;
      else patch_color(m, b, ra);
      return ra;
    } else {
      if ( ma == m.end() ) m[a] = rb;
      else patch_color(m, a, rb);
      return rb;
    }
  }
  void process(string &s)
  {
    int has_left = 0;
    int left = 0;
    int color = 0;
    cmap m;
    vector<room_row> r;
    for ( int i = 0; i < N; ++i )
    {
      if ( s[i] == '#' )
      {
        row[i] = -1;
        if ( !has_left ) continue;
        // fill inerval left .. i with color
        if ( color == next_color - 1 )
          fill(row.begin() + left, row.begin() + i, color);
        else
          r.push_back({ left, i, color});
        has_left = 0;
        continue;
      }
      int old = row[i];
      if ( !has_left )
      {
        has_left = 1;
        left = i;
        if ( old == -1 ) color = get_new_color();
        else color = get_color(m, old);
        continue;
      }
      if ( old == -1 ) continue;
      old = get_color(m, old);
      if ( old == color ) continue;
      // is current color is newly added ?
      if ( color == next_color - 1 )
      {
        color_cnt--;
        color = old;
        next_color--;
        continue;
      }
      color = merge_colors(m, color, old);
    }
    for ( auto &cr: r )
      fill(row.begin() + cr.left, row.begin() + cr.end, get_color(m, cr.color));
    if ( has_left ) fill(row.begin() + left, row.end(), get_color(m, color));
  }
#ifdef DEBUG
  void dump()
  {
    for ( int i = 0; i < N; ++i )
    {
      if ( row[i] == -1 ) putc('#', stdout);
      else printf("%c", '#' + row[i] % 0x50);
    }
    printf("\n");
  }
#endif
};
 
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n, m;
  cin>>n>>m;
  cr c(m);
  for ( int i = 0; i < n; i++ )
  {
    string s;
    cin>>s;
    c.process(s);
#ifdef DEBUG
    c.dump();
#endif
  }
printTime("end");
  printf("%d\n", c.color_cnt);
}
