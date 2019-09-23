#include<bits/stdc++.h>
using namespace std;

void merge(float *A,int l,int u)
{
  /*int w=l;
  cout<<"before ";
  while(w<=u)
  {
    cout<<A[w]<<" ";
    w++;
  }
  cout<<endl;*/
  if(l==u) return;
  int m = (l+u)/2;
  if(l!=u)
  {
    merge(A,l,m);
    merge(A,m+1,u);
  }
  int i=l;
  int j=m+1;
  while(j<=u)
  {
    if(i==j) break;
    else if(A[j]<=A[i])
    {
      bool flag=false;
      if(A[j]<A[i]) flag=true;
      int q=j;
      float p=A[j];
      //cout<<"pp"<<p<<"pp";
      while(q>i)
      {
        A[q]=A[q-1];
        q--;
      }
      A[i]=p;
      if(flag) i++;
      j++;
    }
    else i++;
  }
  /*w=l;
  cout<<"after ";
  while(w<=u)
  {
    cout<<A[w]<<" ";
    w++;
  }
  cout<<endl;*/
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    float A[n];
    int o=0;
    while(o<n)
    {
      int x,y;
      cin>>x;
      cin>>y;
      A[o]=sqrt(x*x+y*y);
      //cout<<A[o]<<" and ";
      o++;
    }
    merge(A,0,n-1);
    /*int f=0;
    while(f<n)
    {
      cout<<A[f]<<"k";
      f++;
    }*/
    int mid=n/2;
    int w;
    if(n%2==0) w=A[mid-1]/1;
    else w=A[mid]/1;
    cout<<w<<endl;
  }
}
