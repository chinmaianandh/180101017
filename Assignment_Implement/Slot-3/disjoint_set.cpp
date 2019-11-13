#include<bits/stdc++.h>
using namespace std;

int head(int *P,int *R,int x)
{
  if(P[x]==x) return x;
  else
  {
    int y=head(P,R,P[x]);
    P[x]=y;
    R[x]=0;
    R[y]++;
    return y;
  }
}

void combo(int *P, int *R, int x, int y)
{
  int px=head(P,R,x);
  int py=head(P,R,y);
  if(R[x]>=R[y])
  {
    P[py]=px;
    R[px]++;
  }
  else
  {
    P[px]=py;
    R[py]++;
  }
  //return 1;
}

void print_heads(int *P,int *R, int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<head(P,R,i)<<" ";
  }
  cout<<endl;
}

int main()
{
  int n=10;
  //cin>>n;

  int parent[n];
  int rank[n]={ 0 };
  for(int l=0;l<n;l++) parent[l]=l;

  print_heads(parent,rank,n);
  combo(parent,rank,1,5);
  combo(parent,rank,2,8);
  print_heads(parent,rank,n);
  combo(parent,rank,1,8);
  print_heads(parent,rank,n);
}
