#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
    https://cses.fi/problemset/task/1666
*/
 
int main()
{
    int n,m;//Broj gradova, broj cesta
    cin>>n>>m;
    vector<vector<int>> V(n+1);
    vector<pair<int,int>> Ceste;
    //Napravi vektor vektora sa svim povezanim gradovima
    //grad u indeksu, povezani gradovi su elementi
    for(int i=0;i<m;i++)
    {
        int c1,c2;//grad1, grad2
        cin>>c1>>c2;
        V[c1].push_back(c2);
        V[c2].push_back(c1);
    }
    vector<int> Visit(n+1,-1);//Vektor posjecenosti, postavlja sve na -1
    int count=0;
    for(int i=1;i<n+1;i++)
    {
        if(Visit[i]==-1)//Ako nije posjecen
        {
            if(count!=0)
            {
                pair<int,int> temp;
                temp.first=1;
                temp.second=i;
                Ceste.push_back(temp);
            }
            count++;
            //cout<<"Visit==-1"<<endl;
            queue<int> Q;
            Q.push(i);
            Visit[i]=1;
            while(!Q.empty())
            {
                int br=Q.front();
                Q.pop();
                for(int grd : V[br])
                {
                    if(Visit[grd]==-1)
                    {
                        Visit[grd]=1;
                        Q.push(grd);
                    }
                }
            }
        }
    }
    //cout<<"Kraj";
    cout<<Ceste.size()<<endl;
    for(auto [r,s] : Ceste)
    {
        cout<<r<<" "<<s<<endl;
    }
}
