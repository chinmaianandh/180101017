#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> B(n,0);
  vector<vector<int>> A(n,B);
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    A[x-1][y-1]=1;
    A[y-1][x-1]=1;
  }
  cout<<"Enter the vertex at which BFS starts : ";
  int v1,x;
  cin>>v1;
  bool visited[n]={ false };
  queue<int> Q;
  Q.push(v1-1);
  visited[v1-1]=true;
  while(!Q.empty())
  {
    x=Q.front();
    Q.pop();
    cout<<x+1<<" ";
    for(int i=0;i<n;i++)
    {
      if(A[x][i]==1 && visited[i]==false)
      {
        Q.push(i);
        visited[i]=true;
      }
    }
  }
  cout<<endl;
}
