#include<iostream>
#include<cmath>

using namespace std;

long double FindKth(long double *A,int n,int k)
{
  int j=-1;
  int i=0;
  long double p = A[n-1];
  while(i<n-1)
  {
    if(A[i]<=p)
    {
      swap(A[i],A[j+1]);
      j++;
      i++;
    }
    else i++;
  }
  if(k==j+2) return p;
  else if(k<j+2) return FindKth(A,j+1,k);
  else return FindKth(A+j+1,n-j-2,k-j-2);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long double A[n];
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
    cout<<FindKth(A,n,(n+1)/2)<<endl;
    /*int f=0;
    while(f<n)
    {
      cout<<A[f]<<"k";
      f++;
    }*/
    /*int mid=n/2;
    int w;
    if(n%2==0) w=A[mid-1]/1;
    else w=A[mid]/1;
    cout<<w<<endl;*/
  }
}
