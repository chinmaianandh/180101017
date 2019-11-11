#include<bits/stdc++.h>
using namespace std;

struct node
{
  char value;
  vector<node*> C;
  bool eow=false;
};

void add_word(node *root, string s)
{
  if(s=="")
  {
    root->eow=true;
    return;
  }
  int i;
  vector<node*> ch=root->C;
  for(i=0;i<ch.size();i++)
  {
    if(ch[i]->value==s[0])
    {
      //cout<<s.substr(1,s.size()-1);
      add_word(ch[i],s.substr(1,s.size()-1));
      break;
    }
  }
  if(i==ch.size())
  {
    node *temp=root;
    for(int j=0;j<s.size();j++)
    {
      node *k=new node;
      k->value=s[j];
      temp->C.push_back(k);
      temp=temp->C[temp->C.size()-1];
      if(j==s.size()-1) temp->eow=true;
    }
  }
}

bool search(node *root, string s)
{
  if(s=="" && root->eow) return true;
  int i;
  vector<node*> ch=root->C;
  for(i=0;i<ch.size();i++)
  {
    if(ch[i]->value==s[0])
    {
      return search(ch[i],s.substr(1,s.size()-1));
    }
  }
  return false;
}

int main()
{
  int n;
  cin>>n;
  string A[n];
  for(int i=0;i<n;i++)  cin>>A[i];

  node *root=new node;
  root->value=':';

  int i=0;
  for(i=0;i<n;i++)
  {
    string b=A[i];
    reverse(b.begin(),b.end());
    //cout<<b<<endl;
    if(A[i]!=b)
    {
      if(search(root,b))
      {
        cout<<"Yes"<<endl;
        return 0;
      }
      else  add_word(root,A[i]);
    }
  }
  if(i==n) cout<<"No"<<endl;
  return 0;
  /*add_word(root,"hell");
  cout<<search(root,"bell")<<endl;
  cout<<search(root,"hell")<<endl;
  add_word(root,"bell");
  cout<<search(root,"bell")<<endl;
  cout<<search(root,"heman")<<endl;
  add_word(root,"heman");
  cout<<search(root,"heman")<<endl;
  node *temp=root;
  while(1)
  {
    cout<<temp->value;
    if(temp->eow) break;
    if(!temp->C.empty())
    {
      temp=temp->C[0];
    }
  }
  cout<<endl<<"done"<<endl;*/
}
