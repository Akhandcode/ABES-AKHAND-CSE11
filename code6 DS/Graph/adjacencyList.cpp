#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int v,e;
    cout<<"how many vertices are there in the graph: ";
    cin>>v;
    cout<<"how many edges are in the graph: ";
    cin>>e;  
    vector<vector<int>>Adj(v);
    for(int i=0; i<e; i++)
    {
        int a, b;
        cout<<"enter end points of edge "<<(i+1)<<": ";
        cin>>a>>b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    } 
    cout<<"Adjacency List";
    for(int i=0; i<v; i++)
    {
        cout<<"Vertex "<<i<<" -> ";
        for(int j=0; j<Adj[i].size(); j++)
        {
            cout<<Adj[i][j];
            if(j < Adj[i].size()-1)
                cout<<",";
        }
        cout<<"\n";
    }    
    return 0;
}
