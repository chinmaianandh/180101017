#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int nn=n;
  int arr[m][3];
  int i=0;
  while(i<m)
  {
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    if(arr[i][2]%2==0) n++;
    i++;
  }
  bool G[n+1][n+1]={ false };
  i=0;
  while(i<m)
  {
    if(arr[i][2]%2==1)
    {
      G[arr[i][0]][arr[i][1]]=true;
      G[arr[i][1]][arr[i][0]]=true;
    }
    else
    {
      G[arr[i][0]][nn+1]=true;
      G[nn+1][arr[i][1]]=true;
      G[arr[i][1]][nn+1]=true;
      G[nn+1][arr[i][0]]=true;
      nn++;
    }
    i++;
  }
  int colour[n+1]={ 0 };



  int count=0;
  vector<int> s0;
  i=1;
  while(i<=n)
  {
    s0.push_back(i);
    i++;
  }
  vector<int> s1,s2,temp;
  int i1=0,i2=0;

  /*for(int o=1;o<=n;o++)
  {
    for(int p=1;p<=n;p++) cout<<G[o][p]<<" ";
    cout<<endl;
  }*/

  while(count!=n)
  {
    if(i1==s1.size() && i2==s2.size())
    {
      s1.push_back(s0[0]);
      colour[s0[0]]=1;
      temp=s1;
      i=i1;
      //s0.erase(s0.begin());
    }
    int k=0;
    while(k<s0.size())
    {
      //cout<<" "<<s0[k];
      if(temp[i]==s0[k]) s0.erase(s0.begin()+k);
      k++;
    }
    //cout<<endl;
    for(int j=1;j<=n;j++)
    {
      if(G[temp[i]][j]==true)
      {
        if(colour[temp[i]]==colour[j])
        {
          cout<<"Yes"<<endl;
          //cout<<temp[i]<<" "<<j<<endl;
          //cout<<colour[temp[i]]<<" "<<colour[j]<<endl;
          return 0;
        }
        else if(colour[j]==0)
        {
          if(colour[temp[i]]==1)
          {
            colour[j]=2;
            s2.push_back(j);
          }
          else
          {
            colour[j]=1;
            s1.push_back(j);
          }
        }
      }
    }
    count++;
    i++;
    if(i==temp.size())
    {
      if(colour[temp[i-1]]==1)
      {
        i1=i;
        i=i2;
        temp=s2;
      }
      else if(colour[temp[i-1]]==2)
      {
        i2=i;
        i=i1;
        temp=s1;
      }
    }
  }
  cout<<"No"<<endl;
  /*i=0;
  while(i<s1.size()) {cout<<" "<<s1[i]; i++;}
  cout<<endl;
  i=0;
  while(i<s2.size()) {cout<<" "<<s2[i]; i++;}
  cout<<endl;*/
  return 0;
}
