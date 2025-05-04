#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("fma,bmi,bmi2")
using namespace std;
typedef long long ll;
 
int n; 
ll x;
 
int na = 0, nb = 0, nc = 0, nd = 0;
ll a[10], b[10], c[10], d[10]; 
 
int ma = 1, mb = 1, mc = 1, md = 1;
ll sa[1024] = {0}, sb[1024] = {0}, sc[1024] = {0}, sd[1024] = {0};
 
ll buf[1024];
 
bool vis1[1024][1024] = {false};
bool vis2[1024][1024] = {false};
priority_queue<pair<ll, pair<int, int>>> pq1, pq2;
void init_priority_queues()
{
    pq1.push({0LL, {0, 0}});
    vis1[0][0] = true;
    pq2.push({sc[mc-1] + sd[md-1], {mc - 1, md - 1}});
    vis2[mc - 1][md - 1] = true;
}
 
ll top1()
{
    if (pq1.empty())
        return LLONG_MIN / 3;
    return -pq1.top().first;
}
void poop1()
{
    if (pq1.empty())
        return;
    auto [i, j] = pq1.top().second;
    pq1.pop();
    if (i + 1 < ma && !vis1[i + 1][j])
    {
        pq1.push({-(sa[i + 1] + sb[j]),{i + 1, j}});
        vis1[i + 1][j] = true;
    }
    if (j + 1 < mb && !vis1[i][j + 1])
    {
        pq1.push({-(sa[i] + sb[j + 1]),{i, j + 1}});
        vis1[i][j + 1] = true;
    }
}
 
ll top2()
{
    if (pq2.empty())
        return LLONG_MIN / 3;
    return pq2.top().first;
}
void poop2()
{
    if (pq2.empty())
        return;
    auto [i, j] = pq2.top().second;
    pq2.pop();
    if (i > 0 && !vis2[i - 1][j])
    {
        pq2.push({sc[i - 1] + sd[j],{i - 1, j}});
        vis2[i - 1][j] = true;
    }
    if (j > 0 && !vis2[i][j - 1])
    {
        pq2.push({sc[i] + sd[j - 1],{i, j - 1}});
        vis2[i][j - 1] = true;
    }
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> x;
 
    ll ans = 0;
    if (n < 4)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int k = 0; k < (1 << n); k++)
        {
            ll s = 0;
            for (int i = 0; i < n; i++)
                if (k & (1 << i))
                    s += a[i];
            if (s == x)
                ans++;
        }
        cout << ans << '\n';
        return 0;
    }
 
    for (int i = 0; i < n / 4; i++)
        cin >> a[na++];
    for (int i = n / 4; i < n / 2; i++)
        cin >> b[nb++];
    for (int i = n / 2; i < 3 * n / 4; i++)
        cin >> c[nc++];
    for (int i = 3 * n / 4; i < n; i++)
        cin >> d[nd++];
 
    for (int i = 0; i < na; i++)
    {
        int prev = ma;
        for (int j = 0; j < prev; j++)
            if (sa[j] + a[i] <= x)
                sa[ma++] = sa[j] + a[i];
        merge(sa, sa + prev, sa + prev, sa + ma, buf);
        copy(buf, buf + ma, sa);
    }
    for (int i = 0; i < nb; i++)
    {
        int prev = mb;
        for (int j = 0; j < prev; j++)
            if (sb[j] + b[i] <= x)
                sb[mb++] = sb[j] + b[i];
        merge(sb, sb + prev, sb + prev, sb + mb, buf);
        copy(buf, buf + mb, sb);
    }
    for (int i = 0; i < nc; i++)
    {
        int prev = mc;
        for (int j = 0; j < prev; j++)
            if (sc[j] + c[i] <= x)
                sc[mc++] = sc[j] + c[i];
        merge(sc, sc + prev, sc + prev, sc + mc, buf);
        copy(buf, buf + mc, sc);
    }
    for (int i = 0; i < nd; i++)
    {
        int prev = md;
        for (int j = 0; j < prev; j++)
            if (sd[j] + d[i] <= x)
                sd[md++] = sd[j] + d[i];
        merge(sd, sd + prev, sd + prev, sd + md, buf);
        copy(buf, buf + md, sd);
    }
 
    init_priority_queues();
    ll prev = -1;
    ll prev_cnt = 0;
    while (pq1.size())
    {
        ll val1 = top1();
        poop1();
        if (val1 == prev)
        {
            ans += prev_cnt;
            continue;
        }
 
        while (val1 + top2() > x)
            poop2();
        ll cnt = 0;
        while (val1 + top2() == x)
            cnt++, poop2();
        ans += cnt;
        prev = val1;
        prev_cnt = cnt;
 
    }
 
    cout << ans << '\n';
 
    return 0;
}
