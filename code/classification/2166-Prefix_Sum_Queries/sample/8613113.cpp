#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <string>
 
using namespace std;
 
int getInd(int x, int k){
    int z = x/k;
 
    if (x%k){
        return z+1;
    }
 
    return z;
}
 
int main()
{
    int n, q, v, k, u, a, b; cin >> n >> q;
    int x[n+1], ind1=0, ind2=0;
    long long a1[getInd(n, 450)+1], a2[getInd(n, 25)+1];
    long long b1[getInd(n, 450)+1], b2[getInd(n, 25)+1], s1 = 0, m1 = 0, s2 = 0, m2 = 0;
 
    for (int i = 1; i < n+1; i++){
        cin >> x[i];
    }
 
    for (int i = 1; i < n+1; i++){
        if (i%450 == 1){
            a1[ind1] = s1;
            b1[ind1++] = m1;
            s1 = m1 = 0;
        }
 
        if (i%25 == 1){
            a2[ind2] = s2;
            b2[ind2++] = m2;
            s2 = m2 = 0;
        }
 
        s1 += x[i];
        s2 += x[i];
        m1 = max(m1, s1);
        m2 = max(m2, s2);
    }
 
    for (int i = 0; i < q; i++){
        cin >> v;
 
        if (v == 1){
            cin >> k >> u;
            ind1 = getInd(k, 450);
            ind2 = getInd(k, 25);
            a1[ind1] += (u-x[k]);
            a2[ind2] += (u-x[k]);
            s1 = m1 = 0;
            s2 = m2 = 0;
            x[k] = u;
 
            for (int i = (ind1-1)*450+1; i < min(n+1, ind1*450+1); i++){
                s1 += x[i];
                m1 = max(m1, s1);
            }
 
            for (int i = (ind2-1)*25+1; i < min(n+1, ind2*25+1); i++){
                s2 += x[i];
                m2 = max(m2, s2);
            }
 
            b1[ind1] = m1;
            b2[ind2] = m2;
        }
        else{
            cin >> a >> b;
            s1 = 0;
            m1 = max(x[a], 0);
            int i = a;
 
            while (i <= b){
                if (i%450 == 1 && (i + 450) <= b+1){
                    ind1 = (i/450)+1;
                    m1 = max(m1, s1+b1[ind1]);
                    s1 += a1[ind1];
                    i += 450;
                }
                else if (i%25 == 1 && (i+25) <= b+1){
                    ind1 = (i/25)+1;
                    m1 = max(m1, s1+b2[ind1]);
                    s1 += a2[ind1];
                    i += 25;
                }
                else{
                    s1 += x[i];
                    m1 = max(m1, s1);
                    i++;
                }
            }
 
            cout << m1 << endl;
            }
        }
 
    return 0;
}
