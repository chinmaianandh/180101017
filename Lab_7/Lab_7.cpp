#include<bits/stdc++.h>

using namespace std;

bool compare(string a,string b)
{
  bool flag=false;
  string x=a.append(b);
  string y=b.append(a);
  if(x<y)
  {
    flag=true;
  }
  if (flag) return  false;
  else return true;
}


int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int t;
    cin>>t;
    string A[t];
    int i=0;
    while(i!=t)
    {
      cin>>A[i];
      i++;
    }
    sort(A,A+t,compare);
    for(i=0;i<t;i++)
    {
      cout<<A[i];
    }
    cout<<endl;
  }
}
