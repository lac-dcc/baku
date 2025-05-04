#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector <long> applicants;
    for (int i = 0; i < n; i++){
        long temp;
        cin >> temp;
        applicants.push_back(temp);
    }
    vector <long> apartments;
    for (int i = 0; i < m; i++){
        long temp;
        cin >> temp;
        apartments.push_back(temp);
    }
    int count = 0;
 
    sort(apartments.begin(), apartments.end());
    sort(applicants.begin(), applicants.end());
    int x = 0;
    int y = 0;
    while (x < applicants.size() && y < apartments.size()){
        long min_v = applicants[x] - k;
        long max_v = applicants[x] + k;
        if (apartments[y] <= max_v && apartments[y] >= min_v){
            count++;
            x++;
            y++;
        }
        else if (apartments[y] < min_v){
            y++;
        }
        else if (apartments[y] > max_v){
            x++;
        }
    }
    cout << count << endl;
    
    // fclose(stdin);
    // fclose(stdout);
}
