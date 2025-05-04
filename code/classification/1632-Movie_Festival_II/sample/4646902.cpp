#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > Filmes;
const int MAXN = 2e5 + 10;
int Pulei[MAXN];
multiset<int> usando;
 
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int A, B;
        cin >> A >> B;
        //Se tiver dando WA, pode ter que mudar a o tipo
        Filmes.emplace_back(A, B);
    }
    sort(Filmes.begin(), Filmes.end(), cmp);
    int resp = 0;
    for (int i = 0; i < Filmes.size(); i++)
    {
        auto [comec, fim] = Filmes[i];
        if (!usando.empty())
        {
            auto abaixo = usando.upper_bound(comec);
            if (abaixo != usando.begin())
            {
                abaixo--;
                usando.erase(abaixo);
            }
        }
        if (usando.size() == K) continue;
        resp++; usando.insert(fim);
    }
    cout << resp;
}
