#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

struct point
{
  int x;
  int y;
};

double dist(point p1,point p2)
{
  return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));
}

int orient(point p1,point p2,point p3)
{
  int val = (p2.y - p1.y)*(p3.x - p2.x)-(p2.x - p1.x)*(p3.y - p2.y);
  if (val == 0) return 0;
  else if(val>0) return 1;
  else return 2;
}

void merge(point *A,int l,int u)
{
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
    else if(orient(A[0],A[i],A[j])!=1)
    {
      bool flag=false;
      if(orient(A[0],A[i],A[j])==2) flag=true;
      int q=j;
      point p=A[j];
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
}


int main()
{
  int T;
  cin>>T;
  int i=0;
  point A[T];
  while(i<T)
  {
    cin>>A[i].x;
    cin>>A[i].y;
    i++;
  }
  i=0;
  int k=i;
  i++;
  while(i<T)
  {
    if(A[i].x<A[k].x) k=i;
    else if((A[i].x==A[k].x)&&(A[i].y<A[k].y)) k=i;
    i++;
  }
  swap(A[0],A[k]);
  //cout<<A[0].x<<" "<<A[0].y<<endl;
  merge(A,1,T-1);
  /*i=0;
  while(i<T)
  {
    cout<<A[i].x<<" "<<A[i].y<<endl;
    i++;
  }*/
  vector<point> C;
  point p;
  C.push_back(A[0]);
  p = A[1];
  i=2;
  while(i<T)
  {
    if(orient(A[0],p,A[i])==1)
    {
      C.push_back(p);
      p=A[i];
    }
    else if(orient(A[0],p,A[i])==0)
    {
      /*cout<<A[0].x<<" p "<<A[0].y<<endl;
      cout<<p.x<<" p "<<p.y<<endl;
      cout<<A[i].x<<" p "<<A[i].y<<endl;
      cout<<dist(A[0],A[i])<<" d "<<dist(A[0],p)<<endl;*/
      if(dist(A[0],A[i])>dist(A[0],p))
      {
        p=A[i];
      }
    }
    i++;
  }
  C.push_back(p);
  int m=C.size();
  /*cout<<m<<endl;
  i=0;
  while(i<m)
  {
    cout<<C[i].x<<" "<<C[i].y<<endl;
    i++;
  }*/

  if(m<3)
  {
    cout<<"Not Possible"<<endl;
    return 0;
  }
  vector<point> H;
  H.push_back(C[0]);
  H.push_back(C[1]);
  i=2;
  int l;
  while(i<m)
  {
    l=H.size();
    if(orient(H[l-2],H[l-1],C[i])==1)
    {
      H.push_back(C[i]);
      i++;
    }
    else
    {
      H.pop_back();
    }
  }
  int h=H.size();
  i=0;
  cout<<h<<endl;
  while(i<h)
  {
    cout<<H[i].x<<" "<<H[i].y<<endl;
    i++;
  }



  //cout<<"done"<<endl;
}
