#include<bits/stdc++.h>

using namespace std;

struct edge
{
  int i;
  int j;
  int k;
};

bool compare(edge a,edge b)
{
  if(a.k<=b.k) return true;
  else return false;
}

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

int main()
{
  int max=1000000007;
  int n,m;
  cin>>n>>m;
  edge A[m];
  for(int l=0;l<m;l++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    A[l].i=x;
    A[l].j=y;
    A[l].k=z;
  }
  sort(A,A+m,compare);
  /*for(int l=0;l<m;l++)
  {
    cout<<A[l].k<<" ";
  }*/
  int parent[n+1];
  int rank[n+1]={ 0 };
  for(int l=0;l<=n;l++) parent[l]=l;

  vector<edge> out;
  for(int l=0;l<m;l++)
  {
    if(head(parent,rank,A[l].i)==head(parent,rank,A[l].j))
    {
      //cout<<A[l].i<<" "<<A[l].j<<endl;
      continue;
    }
    else
    {
      out.push_back(A[l]);
      combo(parent,rank,A[l].i,A[l].j);
    }
  }

  cout<<out.size()<<endl;
  for(int l=0;l<out.size();l++)
  {
    cout<<out[l].i<<" "<<out[l].j<<" "<<out[l].k<<endl;
  }
}
