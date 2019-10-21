#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> V;
int count(int i, int j,int c,int n,int m,vector<vector<int>> A)
{
  c++;
  //cout<<"("<<i<<","<<j<<") ";
  V[i][j]=true;
  if(j<m-1 && A[i][j]==A[i][j+1] && !V[i][j+1]) c=count(i,j+1,c,n,m,A);
  if(j>0 && A[i][j]==A[i][j-1] && !V[i][j-1]) c=count(i,j-1,c,n,m,A);
  if(i<n-1 && A[i][j]==A[i+1][j] && !V[i+1][j]) c=count(i+1,j,c,n,m,A);
  if(i>0 && A[i][j]==A[i-1][j] && !V[i-1][j]) c=count(i-1,j,c,n,m,A);
  return c;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> A;
  vector<int> B;
  for(int i=0;i<m;i++) B.push_back(0);
  for(int i=0;i<n;i++) A.push_back(B);
  int k;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    int x,y;
    cin>>x>>y;
    A[x][y]=1;
  }
  //vector<vector<bool>> V;
  vector<bool> W;
  for(int i=0;i<m;i++) W.push_back(false);
  for(int i=0;i<n;i++) V.push_back(W);
  int max=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(!V[i][j] && A[i][j]==1)
      {
        //cout<<endl;
        int cc=count(i,j,0,n,m,A);
        if(cc>max) max=cc;
      }
    }
  }
  cout<<max<<endl;
}
