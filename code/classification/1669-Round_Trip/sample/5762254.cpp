#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph;
    graph.resize(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        //cout<<7;
    }
    //cout<<7;
    set<int> mask;
    vector<int> way;
    for(int i=0;i<n;i++)
        mask.insert(i);
    vector<int> before;
    before.resize(n);
    while(mask.size()!=0)
    {
        //cout<<7;
        set<int> current;
        auto it=mask.begin();
        vector<int> q;
        q.push_back(*it);
        current.insert(*it);
        int pointer=0;
        before[*it]=-1;
        vector<int> h2;
        h2.push_back(*it);
        while(pointer<q.size())
        {
            for(int i=0;i<graph[q[pointer]].size();i++)
            {
                //cout<<7;
                int h1=graph[q[pointer]][i];
                auto k=current.lower_bound(h1);
                auto t=mask.lower_bound(h1);
                if(t!=mask.end())
                {
                    if(*t==h1)
                    {
                        if(k!=current.end())
                        {
                            if(*k==h1)
                            {
                                if(before[q[pointer]]!=h1)
                                {
                                                                    //circle was found
                                    set<int> route1;
                                    way.push_back(h1);
                                    int c=q[pointer];
                                    vector<int> h8;
                                    while((c!=-1)&&(c!=h1))
                                    {
                                        route1.insert(c);
                                        int h7=before[c];
                                        h8.push_back(c);
                                        c=h7;
                                    }
                                    int d=before[h1];
                                    int turning;
                                    while(1)
                                    {
                                        auto yy=route1.lower_bound(d);
                                        if(yy!=route1.end())
                                        {
                                            if(*yy==d)
                                            {
                                                turning=d;
                                                break;
                                            }
                                        }
                                        way.push_back(d);
                                        int hh=before[d];
                                        d=hh;
                                    }
                                    vector<int> h9;
                                    for(int j=0;j<h8.size();j++)
                                    {
                                        h9.push_back(h8[j]);
                                        if(h8[j]==turning)
                                        {
                                            break;
                                        }
                                    }
                                    for(int j=h9.size()-1;j>=0;j--)
                                    {
                                        way.push_back(h9[j]);
                                    }
                                    way.push_back(h1);
                                    cout<<way.size()<<endl;
                                    for(int j=0;j<way.size();j++)
                                    {
                                        cout<<way[j]+1<<" ";
                                    }
                                    return 0;
                                }
                            }
                        }
                         h2.push_back(h1);
                        if(before[q[pointer]]!=h1)
                        {
                            current.insert(h1);
                            q.push_back(h1);
                            before[h1]=q[pointer];
                        }
                    }
                }
            }
            pointer++;
        }
        for(int i=0;i<h2.size();i++)
        {
             mask.erase(h2[i]);
        }
    }
    cout<<"IMPOSSIBLE";
}
