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