#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<bool> vbool;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = b-1; i >= a; i--)
#define FIN ios::sync_with_stdio(false);cin.tie(0);
#define db(x) cout<<#x<<" = "<<x<<"\n"
#define all(v) v.begin(),v.end()
#define modulo(a,b) ((a%b)+b)%b
#define F first
#define S second
const int INF = 1000000010;
const ll INFLL = 1000000000000000000LL;
#define eps 0.000000001
#define mod 1000000007
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
bool equals(pi p, pi q) { return p.first == q.first && p.second == q.second; }
//=======================//
 
using namespace __gnu_pbds;
 
typedef tree<
        int,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
 
 
void josephus() {
    /*
     * Numero elementos de 0 a n-1. El set mantiene los que están vivos. Cuando estoy parado en x
     * necesito al que esté en la pos (x + k) % n. Lo pongo como nuevo x y mato al x actual.
     */
    int n,k; cin >> n >> k;
    ordered_set alive;
    for(int i = 0; i < n; i++) {
        alive.insert(i);
    }
    int dead = 0;
    while(n > 0) {
        dead = (dead + k) % n;
        auto deadPerson = alive.find_by_order(dead);
        cout << *deadPerson + 1 << (n == 1 ? "\n" : " ");
        alive.erase(deadPerson);
        n--;
    }
}
 
void josephus_queries() {
    int q; cin >> q;
    while(q--) {
        int n,k; cin >> n >> k;
        if(2*k <= n) {
            cout << 2*k << "\n";
            continue;
        }
        int a = (1<<30);
        while(!(a&n)) {
            a >>= 1;
        }
        int l = n-a;
        k -= l;
        assert(k > 0);
        //Calculo la rta para a,k
        int x = 0;
        int s = a/2;
        int vueltas = 0;
        while(s > 0 && x+s < k) {
            x += s;
            s /= 2;
            vueltas++;
        }
        int r = k - x - 1;
        int res1 = (1 << (vueltas+1)) * r + (1 << vueltas);
        res1 %= a;
        int res_final = res1 + 2*l;
        if(res_final >= n) {
            res_final = (res_final - n) * 2;
        }
        cout << res_final+1 << "\n";
    }
}
 
void diceCombinations() {
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int r = 0; r <= n; r++) {
        for(int m = 1; m <= 6; m++) {
            if(r-m >= 0) {
                dp[r] += dp[r-m];
                if(dp[r] >= mod) {
                    dp[r] -= mod;
                }
            }
        }
    }
    cout << dp[n] << "\n";
}
 
void minimizingCoins() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(auto& k : c) cin >> k;
    vector<int> dp(x+1, INF);
    dp[0] = 0;
    for(int r = 1; r <= x; r++) {
        for(int coin : c) {
            if(r-coin >= 0) {
                mini(dp[r], dp[r-coin]+1);
            }
        }
    }
    cout << ((dp[x] == INF) ? -1 : dp[x]) << "\n";
}
 
 
void coinCombinations1() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(auto& k : c) cin >> k;
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int r = 1; r <= x; r++) {
        for(int coin : c) {
            if(r-coin >= 0) {
                dp[r] += dp[r-coin];
                if(dp[r] >= mod) {
                    dp[r] -= mod;
                }
            }
        }
    }
    cout << dp[x] << "\n";
}
 
void coinCombinations2() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(auto& k : c) cin >> k;
    sort(all(c));
    vector<vector<int>> dp(n+1, vector<int>(x+1,0));
    F0(i,n+1) dp[i][0] = 1;
    for(int r = 1; r <= x; r++) {
        for(int coinIndex = 0; coinIndex < n; coinIndex++) {
            if(coinIndex > 0) dp[coinIndex][r] = dp[coinIndex-1][r];
            if(r >= c[coinIndex]) {
                dp[coinIndex][r] += dp[coinIndex][r-c[coinIndex]];
                if(dp[coinIndex][r] >= mod) {
                    dp[coinIndex][r] -= mod;
                }
            }
        }
    }
    cout << dp[n-1][x] << "\n";
}
 
void coinCombinations2fast() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(auto& k : c) cin >> k;
    sort(all(c));
    vector<int> dp(x+1);
    dp[0] = 1;
    for(int coin : c) {
        for (int r = 1; r <= x; r++) {
            if (r >= coin) {
                dp[r] += dp[r - coin];
                if (dp[r] >= mod) {
                    dp[r] -= mod;
                }
            }
        }
    }
    cout << dp[x] << "\n";
}
 
void removingDigits() {
    int n; cin >> n;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int x = 1; x <= n; x++) {
        int y = x;
        while(y > 0) {
            mini(dp[x], dp[x-y%10]+1);
            y /= 10;
        }
    }
    cout << dp[n] << "\n";
}
 
void removingDigitsGreedy() {
    int n; cin >> n;
    int res = 0;
    while(n > 0) {
        res++;
        int y = n;
        int mx_digit = 0;
        while(y > 0) {
            maxi(mx_digit, y%10);
            y /= 10;
        }
        n -= mx_digit;
    }
    cout << res << "\n";
}
 
/*
vector<vector<bool>> visited;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string out[] = {"R", "L", "D", "U"};
vector<string> grid;
int n,m;
vector<pi> res;
vector<vector<int>> dist;
bool dfs(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || visited[x][y]) {
        return false;
    }
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        if(dfs(x+dx[i], y+dy[i])) {
            res.emplace_back(x,y);
            return true;
        }
    }
    if(grid[x][y] == 'B') {
        res.emplace_back(x,y);
        return true;
    }
    return false;
}
 
void bfs(int x0, int y0) {
    dist = vector<vector<int>> (n, vector<int>(m, INF));
    queue<pi> Q;
    Q.emplace(x0,y0);
    dist[x0][y0] = 0;
    visited[x0][y0] = true;
    while(!Q.empty()) {
        pi a = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int x = a.first + dx[i], y = a.second + dy[i];
            if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || visited[x][y]) {
                continue;
            }
            visited[x][y] = true;
            Q.emplace(x,y);
            mini(dist[x][y], dist[a.first][a.second]+1);
        }
    }
}
 
void countingRooms() {
    cin >> n >> m;
    visited = vector<vector<bool>>(n, vector<bool>(m));
    grid = vector<string>(n);
    F0(i,n) cin >> grid[i];
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && grid[i][j] == '.') {
                res++;
                dfs(i,j);
            }
        }
    }
    cout << res << "\n";
}
 
void labyrinth() {
    cin >> n >> m;
    visited = vector<vector<bool>>(n, vector<bool>(m));
    grid = vector<string>(n);
    F0(i,n) cin >> grid[i];
    pi A,B;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                A = {i,j};
            } else if (grid[i][j] == 'B') {
                B = {i,j};
            }
        }
    }
    //dfs(A.first, A.second);
    bfs(B.first, B.second);
    if(visited[A.first][A.second]) {
        cout << "YES\n";
        cout << dist[A.first][A.second] << "\n";
        int x = A.first, y = A.second;
        while(!(x == B.first && y == B.second)) {
            for(int i = 0; i < 4; i++) {
                int x1 = x+dx[i], y1 = y+dy[i];
                if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && dist[x1][y1] < dist[x][y]) {
                    cout << out[i];
                    x = x1; y = y1;
                    break;
                }
            }
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}
*/
 
 
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;
/*
void dfs(int x) {
    if(visited[x]) return; visited[x] = true;
    for(int v : adj[x]) dfs(v);
}
 
void bfs(int s) {
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int v : adj[x]) {
            if(!visited[v]) {
                visited[v] = true;
                Q.push(v);
                dist[v] = dist[x] + 1;
            }
        }
    }
}
 
void buildingRoads() {
    int n,m;
    cin >> n >> m;
    visited = vector<bool>(n+1);
    adj = vector<vector<int>>(n+1);
    F0(i,m) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi roads;
    for(int v = 1; v <= n; v++) {
        if(!visited[v]) {
            roads.push_back(v);
            dfs(v);
        }
    }
    cout << roads.size()-1 << "\n";
    for(int i = 0; i < (int)roads.size()-1; i++) {
        cout << roads[i] << " " << roads[i+1] << "\n";
    }
 
}
 
void messageRoute() {
    int n,m; cin >> n >> m;
    visited = vector<bool>(n+1);
    adj = vector<vector<int>>(n+1);
    dist = vector<int>(n+1, INF);
    F0(i,m) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(n);
    if(visited[1]) {
        cout << dist[1] + 1 << "\n";
        int v = 1;
        while(true) {
            cout << v << " ";
            if(v == n) break;
            for(auto vecino : adj[v]) {
                if(dist[vecino]+1 == dist[v]) {
                    v = vecino;
                    break;
                }
            }
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
 
}*/
 
void gridPaths() {
    int n; cin >> n;
    vector<string> grid(n);
    F0(i,n) cin >> grid[i];
    vector<vector<int>> dp(n+2, vector<int>(n+2));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '.') {
                if (dp[i][j] >= mod) dp[i][j] -= mod;
                dp[i + 1][j] += dp[i][j];
                dp[i][j + 1] += dp[i][j];
            }
        }
    }
    cout << (grid[n-1][n-1] == '.' ? dp[n-1][n-1] : 0) << "\n";
}
 
void knapsack() {
    int n,w; cin >> n >> w;
    vector<int> cost(n), benefit(n);
    F0(i,n) {
        cin >> cost[i];
    }
    F0(i,n) {
        cin >> benefit[i];
    }
    vector<int> dp(w+1);
    for(int obj = 0; obj < n; obj++) {
        for(int c = w; c >= 0; c--) {
            if(c+cost[obj] <= w) {
                maxi(dp[c+cost[obj]], dp[c]+benefit[obj]);
            }
        }
    }
    cout << *max_element(all(dp)) << "\n";
}
 
void arrayDescription() {
    int n,m; cin >> n >> m;
    vi a(n); for(int& x : a) cin >> x;
 
    vector<int> dp(m+1);
    if(a[0] == 0) {
        for (int i = 1; i <= m; i++) dp[i] = 1;
    } else {
        dp[a[0]] = 1;
    }
    for(int i = 1; i < n; i++) { // invariante: a cada paso dp[x] es la cantidad de formas de armar el prefijo[0,i]
        // con el iesimo elemento teniendo una x.
        vector<int> new_dp(m+1);
        int mn = 1, mx = m;
        if(a[i] != 0) {
            mn = mx = a[i];
        }
        for(int x = mn; x <= mx; x++) {
            new_dp[x] += dp[x-1] + dp[x];
            if(new_dp[x] >= mod) new_dp[x] -= mod;
            if(x < m) new_dp[x] += dp[x+1];
            if(new_dp[x] >= mod) new_dp[x] -= mod;
        }
        dp = new_dp;
    }
    int sum = 0;
    for(int s : dp) {
        sum += s;
        if(sum >= mod) sum -= mod;
    }
    cout << sum << "\n";
}
 
vector<int> colorOf;
bool can = true;
void bipartiteColor(int x, int color = 0) {
    if(colorOf[x] == color) return;
    if(colorOf[x] != -1 && colorOf[x] != color) {
        can = false;
        return;
    }
    colorOf[x] = color;
    for(int v : adj[x]) {
        bipartiteColor(v, 1-color);
    }
}
 
void buildingTeams() {
    int n,m; cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    colorOf = vector<int>(n+1,-1);
    F0(i,m) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int x = 1; x <= n; x++) {
        if(colorOf[x] == -1) {
            bipartiteColor(x);
        }
    }
    if(!can) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int c = 1; c <= n; c++) {
            cout << colorOf[c] + 1 << (c == n ? "\n" : " ");
        }
    }
 
}
/*
const int nax = 1000000;
vector<vector<ll>> dp(nax+1,vector<ll>(2));
void doDP() {
    dp[1][0] = dp[1][1] = 1;
    for(int x = 2; x <= nax; x++) {
        dp[x][0] = 2*dp[x-1][0] + dp[x-1][1];
        dp[x][1] = dp[x-1][0] + 4*dp[x-1][1];
        dp[x][0] %= mod;
        dp[x][1] %= mod;
    }
}
 
void countingTowers() {
    doDP();
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1])%mod << "\n";
    }
}*/
/*
vector<vector<int>> dp;
string s,t;
int n,m;
 
int editDistanceRec(int i, int j) {
    if(i == n) return m-j;
    if(j == m) return n-i;
    if(dp[i][j] != -1) return dp[i][j];
    int res = min(editDistanceRec(i+1, j), editDistanceRec(i, j+1)) + 1;
    int costo = 1;
    if(s[i] == t[j]) {
        costo = 0;
    }
    mini(res, editDistanceRec(i+1, j+1) + costo);
    return dp[i][j] = res;
}
 
void editDistanceRecursive() {
    cin >> s >> t;
    n = (int)s.size(), m = (int)t.size();
    dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
    cout << editDistanceRec(0,0) << "\n";
}
 
void editDistance() {
    cin >> s >> t;
    n = (int)s.size(), m = (int)t.size();
    dp = vector<vector<int>>(n+1, vector<int>(m+1, INF));
    //dp[i][j] = rta cuando me me falta leer i de s y j de t.
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            if(s[i-1] == t[j-1]) {
                mini(dp[i][j], dp[i-1][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
}*/
 
vector<int> state;
 
const int UNVISITED = 0, EXPLORED = 1, VISITED = 2;
vector<int> cycle;
bool findCycle(int x, int parent = -1) {
    state[x] = EXPLORED;
    for(int v : adj[x]) {
        if(v == parent) continue;
        if(state[v] == UNVISITED) {
            if(findCycle(v, x)) {
                cycle.push_back(x);
                if(x == cycle[0]) { // Soy el primero (y ultimo) del ciclo, termino aca.
                    cout << cycle.size() << "\n";
                    for(int z : cycle) {
                        cout << z << " ";
                    }
                    cout << "\n";
                    exit(0);
                }
                return true;
            }
        } else if(state[v] == EXPLORED) {
            //Encontramos un ciclo
            cycle.push_back(v);
            cycle.push_back(x);
            return true;
        }
    }
    state[x] = VISITED;
    return false;
}
 
void roundTrip() {
    int n,m; cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    state = vector<int>(n+1);
    F0(i,m) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int v = 1; v <= n; v++) {
        if(state[v] == UNVISITED) {
            findCycle(v);
        }
    }
    cout << "IMPOSSIBLE\n";
}
 
void rectangleCutting() {
    int a,b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));
    for(int x = 1; x <= min(a,b); x++) {
        dp[x][x] = 0;
    }
    for(int x = 1; x <= a; x++) {
        for(int y = 1; y <= b; y++) {
            if(x == y) dp[x][y] = 0;
            else {
                for(int z1 = 1; z1 < x; z1++) {
                    mini(dp[x][y], dp[z1][y] + dp[x-z1][y] + 1);
                }
                for(int z2 = 1; z2 < y; z2++) {
                    mini(dp[x][y], dp[x][z2] + dp[x][y-z2] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << "\n";
}
 
void moneySums() {
    int n; cin >> n;
    vi a(n); F0(i,n) cin >> a[i];
    bitset<100001> sums(1); // Lo creo con el valor 1, es decir con sums[0] = true y lo demas en false
    for(int x : a) {
        sums |= (sums << x);
    }
    cout << sums.count()-1 << "\n";
    for(int s = 1; s <= 100000; s++) {
        if(sums[s]) cout << s << " ";
    }
    cout << "\n";
}
 
void removalGame() {
    int n; cin >> n;
    vll x(n);
    ll sum = 0;
    F0(i,n) {
        cin >> x[i];
        sum += x[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    int paridadPrimero = n%2;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                if(paridadPrimero == 1) {
                    dp[i][j] = x[i];
                } else {
                    dp[i][j] = -x[i];
                }
            }
            else {
                if((j-i+1) % 2 == paridadPrimero) {
                    //Quiero maximizar
                    dp[i][j] = max(x[i] + dp[i+1][j], x[j] + dp[i][j-1]);
                } else {
                    //Quiero minimizar
                    dp[i][j] = min(dp[i+1][j] - x[i], dp[i][j-1] - x[j]);
                }
            }
        }
    }
    /*Sist de ecuaciones: sean a y b los puntajes finales jugando de forma optima. Quiero a.
     * a+b = sum
     * a-b = dp[0][n-1]
     * a = (sum + dp[0][n-1]) / 2
     */
    cout << (sum + dp[0][n-1])/2 << "\n";
}
 
void twoSets() {
    int n; cin >> n;
    if(n%4 == 1 || n%4 == 2) {
        cout << "NO\n";
        return;
    }
    vector<int> a,b;
    int start = 1;
    if(n%4 == 3) {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);
        start = 4;
    }
    for(int x = start; x <= n; x+=4) {
        a.push_back(x);
        a.push_back(x+3);
        b.push_back(x+1);
        b.push_back(x+2);
    }
    cout << "YES\n";
    cout << a.size() << "\n";
    for(int x : a) cout << x << " ";
    cout << "\n";
    cout << b.size() << "\n";
    for(int x : b) cout << x << " ";
    cout << "\n";
}
 
void twoSets2() {
    int n; cin >> n;
    vector<ll> dp(n*(n+1)/2+1); // dp[s] = cant de formas de sumar s (en la iteracion x, con el conjunto 1..x)
    dp[0] = 1;
    for(ll x = 1; x <= n; x++) {
        for(ll s = (x*(x+1))/2; s >= x; s--) {
            dp[s] += dp[s-x]; //No meto x (dp[s]) o lo meto y sumo x (dp[s-x])
            if(dp[s] >= mod) dp[s] -= mod;
        }
    }
    ll target = (n * (n+1))/2;
    if(target%2 == 0) {
        int inv2 = (mod+1)/2;
        cout << modulo((dp[target/2] * inv2),mod) << "\n";
    } else {
        cout << "0\n";
    }
 
}
 
void monsters() {
    //Multisource bfs
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    F0(i,n) cin >> grid[i];
    queue<pi> Q;
    pi person;
    const int MONSTER = 0;
    const int PERSON = 1;
    vector<vector<int>> closest(n,vector<int>(m,-1));
    vector<vector<int>> distance(n,vector<int>(m,INF));
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                person = {i,j};
                closest[i][j] = PERSON;
                distance[i][j] = 0;
            } else if(grid[i][j] == 'M') {
                Q.emplace(i,j);
                closest[i][j] = MONSTER;
                distance[i][j] = 0;
            }
        }
    }
    Q.emplace(person);
    while(!Q.empty()) {
        pi p = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            pi r = {p.first+dx[i], p.second+dy[i]};
            if(r.first < 0 || r.first >= n || r.second < 0 || r.second >= m || grid[r.first][r.second] == '#'
            || closest[r.first][r.second] != -1) {
                continue;
            }
            closest[r.first][r.second] = closest[p.first][p.second];
            distance[r.first][r.second] = distance[p.first][p.second] + 1;
            Q.push(r);
        }
    }
    pi border = {-1,-1};
    //Busco algun borde
    for(int i : {0,n-1}) {
        for(int j = 0; j < m; j++) {
            if(closest[i][j] == PERSON) {
                border = {i,j};
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j : {0,m-1}) {
            if(closest[i][j] == PERSON) {
                border = {i,j};
            }
        }
    }
    if(equals(border, {-1,-1})) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<pi> pasos;
        pasos.push_back(border);
        pi actual = border;
        while(actual != person) {
            for(int i = 0; i < 4; i++) {
                pi r = {actual.first + dx[i], actual.second + dy[i]};
                if(r.first < 0 || r.first >= n || r.second < 0 || r.second >= m || grid[r.first][r.second] == '#'
                   || closest[r.first][r.second] != PERSON || distance[r.first][r.second] >= distance[actual.first][actual.second]) {
                    continue;
                }
                actual = r;
                pasos.push_back(r);
                break;
            }
        }
        reverse(all(pasos));
        cout << pasos.size() - 1 << "\n";
        for(int i = 0; i < (int)pasos.size()-1; i++) {
            if(pasos[i+1].first > pasos[i].first) {
                cout << "D";
            } else if(pasos[i+1].first < pasos[i].first) {
                cout << "U";
            } else if(pasos[i+1].second > pasos[i].second) {
                cout << "R";
            } else {
                cout << "L";
            }
        }
        cout << "\n";
    }
 
}
 
vector<vector<pi>> graph;
vector<ll> distll;
 
void dijkstra(int n, int start) {
    vector<bool> processed(n);
    priority_queue<pair<ll,int>> Q;
    Q.emplace(0, start);
    distll[start] = 0;
    while(!Q.empty()) {
        int v = Q.top().second;
        Q.pop();
        if(processed[v]) continue;
        processed[v] = true;
        for(pi p : graph[v]) {
            if(distll[p.first] > p.second + distll[v]) {
                distll[p.first] = p.second + distll[v];
                Q.emplace(-distll[p.first], p.first);
            }
        }
    }
}
 
void shortestRoutes1() {
    //Camino minimo, Dijkstra
    int n,m; cin >> n >> m;
    graph = vector<vector<pi>>(n);
    distll = vector<ll>(n, INFLL);
    F0(i,m) {
        int a,b; cin >> a >> b;
        ll c; cin >> c;
        a--; b--;
        graph[a].emplace_back(b,c);
    }
    dijkstra(n,0);
    for(ll d : distll) {
        cout << d << " ";
    }
    cout << "\n";
}
 
void shortestRoutes2() {
    //Floyd-Warshall
    int n,m,q; cin >> n >> m >> q;
    ll adjMatrix[n][n];
    F0(i,n) F0(j,n) adjMatrix[i][j] = INFLL;
    F0(i,m) {
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        mini(adjMatrix[a][b], c);
        mini(adjMatrix[b][a], c);
    }
    ll minPath[n][n];
    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            if(a == b) minPath[a][b] = 0;
            else minPath[a][b] = adjMatrix[a][b];
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mini(minPath[i][j], minPath[i][k] + minPath[k][j]);
            }
        }
    }
    while(q--) {
        int a,b; cin >> a >> b; a--; b--;
        if(minPath[a][b] == INFLL) {
            cout << "-1\n";
        } else {
            cout << minPath[a][b] << "\n";
        }
    }
}
 
void increasingSubsequence() {
    //Longest increasing subsequence (LIS)
    int n; cin >> n;
    vector<int> minLast(n+1, INF); // minLast[i] = el elemento mas chico que puede tener una lis de largo i
    cin >> minLast[1];
    int res = 1;
    for(int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        if(x > minLast[res]) {
            res++;
            minLast[res] = x;
        } else {
            // Busqueda binaria al primer elemento que sea mayor o igual que x (si es igual no cambia nada)
            /*int l = 1, r = res;
            int ans;
            while(l <= r) {
                int m = (l+r)/2;
                if(minLast[m] >= x) {
                    ans = m;
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            minLast[ans] = x;*/
            //Se puede usar la STL para la busqueda binaria y hacerlo en una sola linea
            *lower_bound(minLast.begin()+1, minLast.begin()+res+1, x) = x;
        }
    }
    cout << res << "\n";
}
 
void projects() {
    map<int,ll> bestUntil;
    bestUntil[0] = 0;
    int n; cin >> n;
    vector<tuple<ll, ll, ll>> intervals(n);
    for(int i = 0; i < n; i++) {
        cin >> get<0>(intervals[i]) >> get<1>(intervals[i]) >> get<2>(intervals[i]);
    }
    sort(all(intervals), [](const tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) {
        return get<1>(a) < get<1>(b);
    });
    ll resSoFar = 0;
    for(auto t : intervals) {
        int a,b; ll c;
        tie(a,b,c) = t;
        auto bestBeforeA = bestUntil.lower_bound(a);
        --bestBeforeA;
        maxi(resSoFar, bestBeforeA->second + c);
        bestUntil[b] = resSoFar;
    }
    cout << resSoFar << "\n";
}
 
void projects2() {
    //Mismo problema, resuelto con coordinate compression
    int n; cin >> n;
    vector<tuple<ll, ll, ll>> intervals(n);
    vector<int> compress;
    for(int i = 0; i < n; i++) {
        cin >> get<0>(intervals[i]) >> get<1>(intervals[i]) >> get<2>(intervals[i]);
        compress.push_back(get<0>(intervals[i]));
        compress.push_back(get<1>(intervals[i]));
    }
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());
    for(int i = 0; i < n; i++) {
        get<0>(intervals[i]) = lower_bound(all(compress), get<0>(intervals[i])) - compress.begin() + 1;
        get<1>(intervals[i]) = lower_bound(all(compress), get<1>(intervals[i])) - compress.begin() + 1;
    }
    sort(all(intervals), [](const tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) {
        return get<1>(a) < get<1>(b);
    });
    /*En vez de ordenar asi, se puede hacer un lo siguiente
     * vector<int> order(n);
     * iota(all(order),0);
     * sort(all(intervals), [&] (int i, int j) {
     *   return get<1>(interval[i]) < get<1>(interval[j])
     * }
     * Y despues usar order cada vez que accedo a interval
     */
    int N = (int)compress.size();
    vector<ll> dp(N+1);
    int index = 0;
    dp[0] = 0;
    for(int t = 1; t <= N; t++) { //Itero en el tiempo
        dp[t] = dp[t-1];
        int a,b;
        ll c;
        tie(a,b,c) = intervals[index];
        while(b == t) { //Considero todos los intervalos que terminan ahora
            maxi(dp[t], dp[a-1]+c);
            index++;
            if(index == n) break;
            tie(a,b,c) = intervals[index];
        }
    }
    cout << dp[N] << "\n";
}
 
void elevatorRides() {
    int n,W;
    cin >> n >> W;
    vi p(n);
    for(int& x : p) cin >> x;
    int maxMask = (1<<n);
    vector<pi> leastElevators(maxMask, {INF, INF}); //leastElevators[b] =
    // {minima cantidad de ascensores para las personas representadas por b, peso usado en el ascensor actual}
    leastElevators[0] = {0, W};
    for(int b = 0; b < maxMask; b++) {
        for(int i = 0; i < n; i++) {
            if(((1 << i) & b) == 0) { //Esta persona esta libre
                if(leastElevators[b].second + p[i] <= W) {
                    mini(leastElevators[(1 << i) | b], {leastElevators[b].first, leastElevators[b].second + p[i]});
                } else {
                    mini(leastElevators[(1 << i) | b], {leastElevators[b].first+1, p[i]});
                }
            }
        }
    }
    cout << leastElevators[maxMask-1].first << "\n";
}
 
void staticRangeSumQueries() {
    int n,q; cin >> n >> q;
    vll a(n);
    vll s(n);
    ll sum = 0;
    F0(i,n) {
        cin >> a[i];
        sum += a[i];
        s[i] = sum;
    }
    F0(i,q) {
        int l,b; cin >> l >> b;
        l--; b--;
        ll res = s[b];
        if(l > 0) {
            res -= s[l - 1];
        }
        cout << res << "\n";
    }
}
 
// Uso: Modificar lo indicado. Llamar a build con el vector inicial. Luego
// queriar con get(L,R): devuelve la respuesta para el intervalo cerrado [L,R].
 
struct SparseTable {
    /* Cosas que hay que modificar cada vez: */
    typedef int elem_t; // El tipo de los elementos.
    int MAXN = 200010;
    elem_t NEUTRO = 1000000010; // Elemento neutro de la operacion
    static elem_t f(elem_t a, elem_t b) { // La funcion que queremos consultar.
        return min(a,b);
    }
    static elem_t f(elem_t a) { // Aplicar f en un rango de un solo elemento. Generalmente es solo la identidad.
        return a;
    }
    bool idempotente = true;
    /* Dice si f es idempotente (repetir un operando varias veces no cambia el resultado),
    como min, max, gcd. Si es idempotente, las queries corren en O(1). Si no, en O(log n). */
 
    /* ============= LISTO. A partir de aca queda todo siempre igual. ============= */
 
    int K;
    vector<vector<elem_t>> st;//[MAXN][K + 1];
    vector<int> log;
    SparseTable() {
        log = vector<int>(MAXN+1);
        log[1] = 0;
        for (int i = 2; i <= MAXN; i++)
            log[i] = log[i/2] + 1;
        K = log[MAXN] + 1;
        st = vector<vector<elem_t>>(MAXN, vector<elem_t>(K+1, NEUTRO));
    }
    void build(vector<elem_t>& array) {
        int N = (int)array.size();
        for (int i = 0; i < N; i++)
            st[i][0] = f(array[i]);
 
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++) {
                st[i][j] = f(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
            }
    }
    elem_t slow_query(int L, int R) {
        elem_t res = NEUTRO;
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                res = f(res, st[L][j]);
                L += 1 << j;
            }
        }
        return res;
    }
    elem_t fast_query(int L, int R) {
        int j = log[R - L + 1];
        elem_t res = f(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
 
    elem_t get(int L, int R) {
        if (idempotente)
            return fast_query(L,R);
        else
            return slow_query(L,R);
    }
};
 
//Ejemplo
void staticRangeMinimumQueries() {
    int n,q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SparseTable st;
    st.build(a);
 
    while(q--) {
        int i,j;
        cin >> i >> j;
        i--; j--;
        cout << st.get(i,j) << "\n";
    }
}
 
/*
Cosas que hay que cambiar cada vez que se quiere usar el segment tree (lo demas es general, sirve siempre):
NEUTRAL_ELEMENT
 El tipo "item". Puede ser un struct o un typedef.
single() La informacion de un nodo dado el valor correspondiente del array. Tipicamente es la identidad
merge(). Dada la informacion de dos nodos hijos, como se unifican para generar la informacion del padre
*/
 
/*struct item {
	ll sum;   //sum of the whole segment
	ll seg;   // maximum sum of a subsegment in the segment
	ll pref;  // maximum sum of a prefix of the segment
	ll suf;   // maximum sum of a suffix of the segment
};*/
typedef long long item;
 
struct segtree {
    int size;
    vector<item> tree;
    item NEUTRAL_ELEMENT = 0;
 
    item single(long long v) {
        return v;
    }
 
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.assign(size*2,NEUTRAL_ELEMENT);
    }
 
    item merge(item a, item b) {
        item res = a+b;
        return res;
    }
 
    void build(int node, int lx, int rx, vector<long long>& a) {
        if (rx-lx == 1) {
            if (lx < (int) a.size()) {
                tree[node] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(2*node+1, lx, m, a);
        build(2*node+2, m, rx, a);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }
 
    void build(vector<long long>& a) {
        build(0,0,size,a);
    }
 
    void set(int i, long long a, int node, int l, int r) {
        if (r - l == 1) {
            tree[node] = a;
            return;
        }
        int m = (l+r) / 2;
        if (i < m)
            set(i,a,2*node+1,l,m);
        else
            set(i,a,2*node+2,m,r);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }
 
    void set(int i, long long a) {
        set(i,a,0,0,size);
    }
 
    item get(int node, int lx, int rx, int L, int R) {
        if (L >= rx || R <= lx) return NEUTRAL_ELEMENT;
        if (lx >= L && rx <= R) return tree[node];
        int m = (lx + rx) / 2;
        item s1 = get(2*node+1, lx, m, L, R);
        item s2 = get(2*node+2, m, rx, L, R);
        return merge(s1,s2);
    }
 
    item get(int L, int R) {
        return get(0,0,size,L,R);
    }
 
};
 
void dynamicRangeSumQueries() {
    int n,q; cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segtree st;
    st.init(n);
    st.build(a);
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int i;
            long long x;
            cin >> i >> x;
            i--;
            st.set(i,x);
        }
        else {
            int l,r; cin >> l >> r;
            l--; r--;
            ll out = st.get(l, r+1);
            cout << out << "\n";
        }
    }
}
 
void xorQueries() {
    int n,q; cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segtree st;
    st.init(n);
    st.build(a);
    while(q--) {
        int op; //cin >> op;
        op = 2;
        if (op == 1) {
            int i;
            long long x;
            cin >> i >> x;
            i--;
            st.set(i,x);
        }
        else {
            int l,r; cin >> l >> r;
            l--; r--;
            ll out = st.get(l, r+1);
            cout << out << "\n";
        }
    }
}
 
void rangeUpdateQueries() {
    int n,q; cin >> n >> q;
    vector<long long> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= sum;
        sum += a[i];
    }
    segtree st;
    st.init(n);
    st.build(a);
    while(q--) {
        int op; cin >> op;
        if (op == 2) {
            int i;
            cin >> i;
            i--;
            cout << st.get(0,i+1) << "\n";
        }
        else {
            int l,r; cin >> l >> r;
            ll u; cin >> u;
            l--; r--;
            ll lValue = st.get(l,l+1);
            st.set(l, lValue + u);
            if(r < n-1) {
                ll rValue = st.get(r+1, r + 2); // El valor de la pos r+1
                st.set(r + 1, rValue - u);
            }
        }
    }
}
 
struct pt {
    ll x, y;
    bool operator==(const pt otro) const {
        return x == otro.x && y == otro.y;
    }
    bool operator<(const pt b) const {
        return x < b.x || (x == b.x && y < b.y);
    }
};
 
bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0; //Mayor estricto para convex hull minimo
}
 
bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0; //Mayor estricto aca tambien
}
 
void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;
 
    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == (int)a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == (int)a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
 
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = (int)down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
 
void convexHull() {
    int n; cin >> n;
    vector<pt> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    convex_hull(a);
    cout << a.size() << "\n";
    for(auto & p : a) {
        cout << p.x << " " << p.y << "\n";
    }
 
}
/*
ll followedByZeros(int primero, int ceros) { // Dado un valor tipo 7000 ( que se expresa como (7,3)), dice cuantas respuestas hay menores que 7000
    if(ceros == 0) {
        return primero + 1;
    }
    if(primero == 0) return 0;
    ll res = primero-1; //El primer digito es distinto de cero
    for (int i = 0; i < ceros; i++) {
        res *= 9; //Los demas digitos pueden ser cualquiera, distinto del anterior
    }
    //El primer digito es cero
    res += answerForDigits[ceros];
    return res;
}
 
ll f(ll nn) {
    string n = to_string(nn);
    int length = (int)n.size();
    ll res = 0;
    char last = '9' + 1;
    for(char c : n) {
        if(c == last) {
            if(c == '0') break;
            res += followedByZeros(c-'0', --length);
            break;
        }
        if(c > last) {
            last = c;
            c--;
        } else {
            last = c;
        }
        res += followedByZeros(c-'0', --length);
    }
    return res;
}*/
 
ll pow9[19];
ll answerForDigits[19];
 
ll solve(string &s, int position = 0) {
    ll c = s[position] - '0';
    int falta = (int)s.size() - 1 - position;
    if(falta == -1) {
        return 1; // Como caso base
    }
    if(position == 0) {
        // El primer valor es 1..c-1, o bien empiezo desde el siguiente dígito, o bien empiezo con c y sigo recursivamente
        return (c-1) * pow9[falta] + answerForDigits[falta] + solve(s, position+1);
    } else {
        int last = s[position-1] - '0'; //Este valor es el previo, está fijo
        if(c < last) {
            //Uso cualquier valor de 0..c-1
            ll res = c * pow9[falta];
            //O bien empiezo con c y resuelvo recursivamente
            return res + solve(s, position+1);
        } else if(c > last) {
            //Uso cualquier valor de 0..c-1 salvo last
            ll res = (c-1) * pow9[falta];
            //O bien empiezo con c y sigo recursivamente
            return res + solve(s, position+1);
        } else { //c == last
            if(c == '0') {
                //No hay opción valida
                return 0;
            } else {
                //Uso cualquier valor de 0..c-1
                return c * pow9[falta];
            }
        }
    }
}
 
void countingNumbers() {
    pow9[0] = 1;
    answerForDigits[0] = 1;
    for(int i = 1; i < 20; i++) {
        pow9[i] = 9 * pow9[i-1];
        answerForDigits[i] = pow9[i] + answerForDigits[i-1];
    }
    ll a; string b; cin >> a >> b;
    ll res = solve(b);
    if(a > 0) {
        string aStr = to_string(a-1);
        res -= solve(aStr);
    }
    cout << res << "\n";
}
 
void dfs(int x, vector<bool>& vis, vector<vector<int>> &adj) {
    if(vis[x]) return;
    vis[x] = true;
    for(int v : adj[x]) {
        dfs(v, vis, adj);
    }
}
 
void highScore() {
    //Bellman-Ford (deteccion de ciclos negativos)
    int n,m; cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    vector<ll> dist(n+1, INFLL);
    vector<bool> reachN(n + 1);
    vector<vector<int>> adjInv(n+1); //Lista de adyacencias (sin pesos) invertida, para saber quienes alcanzan a n
    vector<vector<int>> adj(n+1); //Lista de adyacencias (sin pesos), para saber quienes son alcanzables desde 1
    dist[1] = 0;
    for(int i = 0; i < m; i++) {
        int a,b; ll c;
        cin >> a >> b >> c;
        c *= -1;
        edges.emplace_back(a,b,c);
        adjInv[b].push_back(a);
        adj[a].push_back(b);
        //edges.emplace_back(b,a,c);
    }
    dfs(n, reachN, adjInv);
    vector<bool> reachable(n+1);
    dfs(1, reachable, adj);
    for(int i = 1; i <= n-1; i++) { //Se puede ir hasta n-1 en general. Voy hasta n para ver si hay ciclo negativo
        for(auto e : edges) {
            int a,b; ll c;
            tie(a,b,c) = e;
            if(dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
            }
        }
        /*if(!change) { //Esto es para cortarlo antes si solo estamos buscando el camino minimo
            break;
        }*/
    }
    ll res = dist[n];
    //Ahora me fijo si hay algun ciclo negativo en el camino hacia n. Si lo hubiera, entonces
    //al repetir el recorrido debería cambiar la distancia.
    bool negativeCycle = false;
    for(auto e : edges) {
        int a,b; ll c;
        tie(a,b,c) = e;
        if(dist[b] > dist[a] + c) {
            if(reachN[b] && reachable[b]) {
                negativeCycle = true;
            }
        }
    }
    if(negativeCycle) {
        cout << "-1\n";
    } else {
        cout << -1 * dist[n] << "\n";
    }
}
 
void flightDiscount() {
    //Camino minimo pero puedo dividir una arista del camino por 2.
    //Hago Dijkstra y me guardo para cada vertice la distancia minima si ya use el descuento y si todavia no lo use.
    int n,m; cin >> n >> m;
    vector<vector<pair<int,ll>>> adj(n);
    for(int i = 0; i < m; i++) {
        int a,b; ll c; cin >> a >> b >> c; a--; b--;
        adj[a].emplace_back(b,c);
    }
    vector<vector<ll>> dist(n, vector<ll>(2, INFLL));
    dist[0][0] = dist[0][1] = 0;
    vector<vector<bool>> processed(n,vector<bool>(2));
    priority_queue<tuple<ll,int,int>> Q;
    Q.emplace(0, 0, 0);
    while(!Q.empty()) {
        ll d; int v, usedDiscount;
        tie(d,v,usedDiscount) = Q.top();
        d *= -1;
        Q.pop();
        if(processed[v][usedDiscount]) continue;
        processed[v][usedDiscount] = true;
        for(pi p : adj[v]) {
            if(dist[p.first][usedDiscount] > p.second + dist[v][usedDiscount]) {
                dist[p.first][usedDiscount] = p.second + dist[v][usedDiscount];
                Q.emplace(-dist[p.first][usedDiscount], p.first, usedDiscount);
            }
            if(usedDiscount == 0) {
                //Puedo usarlo ahora
                ll distanceUsingDiscount = p.second/2 + dist[v][0];
                if(dist[p.first][1] > distanceUsingDiscount) {
                    dist[p.first][1] = distanceUsingDiscount;
                    Q.emplace(-dist[p.first][1], p.first, 1);
                }
            }
        }
    }
    cout << dist[n-1][1] << "\n";
 
}
 
void cycleFinding() {
    int n,m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n);
    vector<tuple<ll,ll,ll>> edges(m);
    vector<ll> dist(n, INFLL), parent(n, -1);
    for(int i = 0; i < m; i++) {
        ll a,b,c; cin >> a >> b >> c;
        --a; --b;
        adj[a].emplace_back(b,c);
        edges[i] = {a,b,c};
    }
    bool change;
    ll x; //Algun chabon que haya sido aumentado en la n-esima iteracion. Puedo retroceder desde el para encontrar un ciclo
    for(int i = 0; i < n; i++) {
        change = false;
        for(auto edge : edges) {
            ll a,b,c; tie(a,b,c) = edge;
            if(dist[b] > dist[a] + c) {
                change = true;
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }
    if(!change) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        x = parent[x];
    }
    vector<ll> ciclo;
    ciclo.push_back(x);
    while(true) {
        x = parent[x];
        ciclo.push_back(x);
        if(x == ciclo[0]) break;
    }
    reverse(all(ciclo));
    for(ll v : ciclo) {
        cout << v+1 << " ";
    }
    cout << "\n";
}
 
int main() {
    FIN
    cycleFinding();
	return 0;
}
 
 
