//Problema Disponível em:
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG
#define bug(X) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << " " << X << endl;}
#define bugC(X) {cout << "*** DEBUG *** " << __LINE__ << " " << X << endl;}
#define bugV(X, INI, END) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = INI; i < END; i++) cout << X[i] << ' '; cout << endl;}
#define bugP(X, N) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = 0; i < N; i++) cout << '(' << X[i].first << ',' << X[i].second << ')'; cout << endl;}
#define bugM(X, N, M){cout << "*** DEBUG *** " << __LINE__ << " " << #X << ":\n";for (int i = 0; i < N; i++){ for (int j = 0; j < M; j++) cout << X[i][j] << ' '; cout << endl;}}
#else
#define bug(X) {;}
#define bugC(X) {;}
#define bugV(X, INI, END){;}
#define bugP(X, N){;}
#define bugM(X, N, M){;}
#endif
#define FOR(S, E) for (int I = S; I < E; I++)
#define FORJ(S, E) for (int J = S; J < E; J++)
#define FORK(S, E) for (int K = S; K < E; K++)
#define FORT(S, E) for (int T = S; T < E; T++)
#define FORR(S, E) for (int R = S - 1; R >= E; R--)
#define FORIT(OBJ) for (auto &IT : (OBJ))
#define FORIT_(OBJ) for (auto IT = OBJ.begin(); IT != OBJ.END(); IT++)
#define LLMAX 12345678901234567
#define LLMIN -12345678901234567
#define MAX 1234567890
#define LL long long
#define MIN -1234567890
#define PI pair<int, int>
#define PL pair<LL, LL>
#define PB push_back
#define F first
#define S second
#define LIM 200002
#define MOD 1'000'000'007
using namespace std;
 
struct TL
{
    LL F, S, W;
    
    TL(LL a, LL b, LL c){
        F = a;
        S = b;
        W = c;
    }
 
    TL(){}
 
    bool operator<(TL a){
        return F < a.F;
    }
 
    bool operator>(TL a){
        return F > a.F;
    }
 
    void print(){
        cout << "(" << F << ' ' << S << ' ' << W << ") ";
    }
};
 
 
LL pd[LIM] = {0};
TL arr[LIM];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    
    FOR(1, n+1){
        cin >> arr[I].F >> arr[I].S >> arr[I].W;
    }
 
    arr[0] = {0, 0, 0};
    arr[n + 1] = {LLMAX, 0, 0};
 
    sort(arr, arr + n +1);
 
    FORR(n + 1, 0){
 
        TL temp(arr[R].S, 0, 0);
 
        int ini = R;
        int end = n + 1;
        
        while(ini <= end){
            int mid = (ini + end) / 2;
            
            if(arr[mid] > temp){
                end = mid - 1;
        
            }else{
        
                ini = mid + 1;
            }
        }
 
        pd[R] = max(pd[R], pd[R + 1]);
        pd[R] = max(pd[R], pd[ini] + arr[R].W);
    }
 
    cout << *max_element(pd, pd + n + 1) << endl;
    return 0;
}
