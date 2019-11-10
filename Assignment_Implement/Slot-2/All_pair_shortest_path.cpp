//  All pair shortest path algorithm :
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> A, int n)
{
  //cout<<"begin"<<endl;
  vector<vector<int>> out=A;
  //cout<<"ola"<<endl;
  for(int k=0;k<n;k++)
  {
    //cout<<"k1"<<endl;
    for(int i=0;i<n;i++)
    {
      //cout<<"i1"<<endl;
      for(int j=0;j<n;j++)
      {
        //cout<<"j1"<<endl;
        if(out[i][j]>out[i][k]+out[k][j]) out[i][j]=out[i][k]+out[k][j];
      }
    }
  }
  return out;
}

int main()
{
  int max=1000000007;
  int n,m;
  cin>>n>>m;
  vector<int> B(n,max);
  vector<vector<int>> A(n,B);
  for(int i=0;i<n;i++) A[i][i]=0;
  for(int i=0;i<m;i++)
  {
    int x,y,k;
    cin>>x>>y>>k;
    A[x-1][y-1]=k;
    A[y-1][x-1]=k;
  }
  vector<vector<int>> C=floyd_warshall(A,n);
  //cout<<"done1"<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<C[i][j]<<"  ";
    }
    cout<<endl;
  }
}
