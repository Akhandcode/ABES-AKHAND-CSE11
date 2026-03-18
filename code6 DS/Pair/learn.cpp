// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
//   pair<int,string>p;
//   p={101,"Rama"};
//   p=make_pair(101,"Rama");
//   cout<<p.first<<",";
//   cout<<p.second;
//
queue<pair<int,int>>q;
q.push({0,5});
q.push({1,4});
q.push({2,3});
q.push({3,2});
q.push({2,1});
while(!q.empty())
{
    pair<int,int>p;
    p=q.front();
    q.pop();
    cout<<p.first<<" "<<p.second<<" ";
}
}


int n=grid.size();
int n=grid[0].size();
vector<vector<int>>status(n,vector<int>m,-1));
queue<pair<int,int>>q;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==1)
        {
            q.push((i,j));
            status[i][j]=0;
        }
    }
}
while(!q.empty())
{
    pair<int,int>p;
    p=q.front();
    int i=p.first;
    int j=p.second;
    if(j+i<n)
    {
        if(grid[i][j+1]==1)
        {
            grid[i][j+1]=2;
            status[i][j+1]=status[i][j]+1;
            q.push(i,j-1);
        }
    }
    if(j+i<n)
    {
        if(grid[i][j+1]==1)
        {
            grid[i][j+1]=2;
            status[i][j+1]=status[i][j]+1;
            q.push(i,j-1);
        }
    }
    if(i-1>=0)
    {
        if(grid[i][j+1]==1)
        {
            grid[i][j+1]=2;
            status[i][j+1]=status[i][j]+1;
            q.push(i,j-1);
        }
    }
    if(i+1<n)
    {
        if(grid[i][j+1]==1)
        {
            grid[i+1][j+1]=2;
            status[i+1][j]=status[i][j]+1;
            q.push(i,j-1);
        }
    }
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==1)
        {
            return -1;
        }
        else if(grid[i][j]==2)
        {
            if(status[i][j]>maximun)
            {
                maximun=status[i][j];
            }
        }
    }
    return
}