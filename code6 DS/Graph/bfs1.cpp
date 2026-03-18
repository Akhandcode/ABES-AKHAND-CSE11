#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int N,E;
    cout<<"Enter the no of vertices :";
    cin>>N;
    cout<<"Enter the no of edges:";
    cin>>E;
    vector<int>AdjList[N];
    for(int i=1;i<=E;i++){
        int a,b;
        cout<<" enter the end points of edge"<<i<<":";
        cin>>a>>b;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
     }
     for(int i=0;i<N;i++){
        cout<<i<<":";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j]<<",";
        }
        cout<<endl;
     }
  vector<int >status(N,-1);
  queue<int>Q;
  Q.push(3);
  status[3]=0;
  cout<<" bfs order is :=>";
  while(Q.size()!=0){
    int x=Q.front();
    cout<<x<<" ,";
     Q.pop();
     for(int k=0;k<AdjList[x].size();k++){
      int e=AdjList[x][k];
      if(status[e]==-1){
       status[e]=status[x]+1;
       Q.push(e);
   }
     }
  }
  for(int i=0;i<status.size();i++)
  {
    cout<<i<<" "<<status[i];
    cout<<endl;
  }
}