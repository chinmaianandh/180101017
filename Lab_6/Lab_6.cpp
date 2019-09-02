#include<iostream>
#include<vector>
using namespace std;

int main()
{
  vector<vector<int>> A;
  int n;
  cin>>n;
  int q;
  cin>>q;
  int mau=0,mav=0;
  while(q--)
  {
    int a;
    cin>>a;
    if(a==2)
    {
      if(A.size()==0) cout<<"No Data Available"<<endl;
      else cout<<mau<<endl;
    }
    else if(a==1)
    {
      int u,v;
      cin>>u>>v;
      int i=0;
      while(i!=A.size())
      {
        if(A[i][0]==u)
        {
          A[i][1]=A[i][1]+v;
          if(A[i][1]>mav)
          {
            mav=A[i][1];
            mau=A[i][0];
          }
          break;
        }
        i++;
      }
      if(i==A.size())
      {
        vector<int> V;
        V.push_back(u);
        V.push_back(v);
        A.push_back(V);
        if(v>mav)
        {
          mav=v;
          mau=u;
        }
      }
    }
  }
}
