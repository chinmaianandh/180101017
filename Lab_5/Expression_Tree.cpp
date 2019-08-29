#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int opera(struct tree *,vector<struct block *>);

struct block
{
  string s;
  int value;
};

int prec(char a)
{
  if (a=='^') return 6;
  else if (a=='/' || a=='*') return 5;
  else if (a=='+' || a=='-') return 4;
  else if (a=='=') return 3;
  else if(a=='N') return 0;
  else cout<<"Invalid prec("<<a<<")"<<endl;
}

struct tree
{
  string v;
  char flag;
  struct tree *up=NULL;
  struct tree *l=NULL;
  struct tree *r=NULL;
};

string infixToPrefix(string s)
{
  string out;
  char q='0';
    stack<char> st;
    st.push('N');
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='(') st.push('(');
      else if(s[i]==')')
      {
        while(st.top()!='(')
        {
          out+=" ";
          out+=st.top();
          st.pop();
        }
        st.pop();
      }
      else if(!isalpha(s[i]) && !isdigit(s[i]))
      {
        if(st.top()=='N' || st.top()=='(' || (prec(s[i])>prec(st.top()))) st.push(s[i]);
        else
        {
          while (prec(s[i])<=prec(st.top()))
          {
            out+=" ";
            out+=st.top();
            st.pop();
          }
          st.push(s[i]);
        }
      }
      else
      {
        if((isdigit(q)&&isdigit(s[i]))||(isalpha(q)&&isalpha(s[i]))) out+=s[i];
        else
        {
          out+=" ";
          out+=s[i];
        }
      }
      q=s[i];
    }
    while(st.top()!='N')
    {
      out+=" ";
      out+=st.top();
      st.pop();
    }
    reverse(out.begin(),out.end());
    return out;
}



string token(string a,int k)
{
  string b;
  int i=k;
  while(a[i]!=' ')
  {
    i++;
  }
  b=a.substr(k,i-k);
  reverse(b.begin(),b.end());
  return b;
}

int evaluate(struct tree *root,vector<struct block *> A)
{
  struct tree *T=root;
  if(T->flag == 'i')
  {
    int boom;
    istringstream(T->v) >> boom;
    return boom;
  }
  else if(T->flag == 'o')
  {
    return opera(T,A);
  }
  else if(T->flag == 's')
  {
    if(A.size()!=0)
    {
      for(int j=A.size()-1;j>=0;j--)
      {
        	if(A[j]->s==T->v) return A[j]->value;
      }
    }
    else cout<<"Invalid"<<endl;
    return 0;
  }
  return 0;
}

int opera(struct tree *T,vector<struct block *> A)
{
  string op=T->v;
  if(op=="+") return evaluate(T->l,A)+evaluate(T->r,A);
  else if(op=="-") return evaluate(T->l,A)-evaluate(T->r,A);
  else if(op=="*") return evaluate(T->l,A)*evaluate(T->r,A);
  else if(op=="/") return evaluate(T->l,A)/evaluate(T->r,A);
  else if(op=="^") return pow(evaluate(T->l,A),evaluate(T->r,A));
}

struct tree *addtree(struct tree *cn,struct tree *n)
{
  if(cn->r==NULL)
  {
    cn->r=n;
    n->up=cn;
    if(n->flag=='o')
    {
    	cn=cn->r;
    }

  }
  else if(cn->l==NULL)
  {
    cn->l=n;
    n->up=cn;
    if(n->flag=='o')
    {
    	cn=cn->l;
    }
  }

  else
  {
    cn=cn->up;
    return addtree(cn,n);
  }
  return cn;
}







int main()
{

  int n1;
  cin>>n1;
  while(n1--)
  {
    vector<struct block *> A;
    string a,b;
    int n2;
    cin>>n2;
    while(n2--)
    {
      struct tree *R=NULL;
      cin>>a;
      b=infixToPrefix(a);


      /*cout<<b<<endl;
      int n=3;
      int m1=0;
      while(n--)
      {
        a=token(b,m1);
        m1+=a.size()+1;
        cout<<a<<endl;
      }*/


      int sc=0;
      for(int k=0;k<b.size();k++)
      {
        if(b[k]==' ') sc++;
      }


      //cout<<sc<<endl;
      //cout<<"out"<<endl;


      struct tree *cn=R;
      sc++;
      int m=0;
      while(sc--)
      {
        a=token(b,m);
        m+=a.size()+1;

        if((a.size()==1)&&(!isdigit(a[0]))&&(!isalpha(a[0])))
        {
          //cout<<"oper"<<endl;
          struct tree *t;
          t=new tree();
          t->flag='o';
          t->v=a;
          if(R==NULL)
          {
            R=t;
            cn=R;
          }
          else
          {
            cn=addtree(cn,t);
          }
        }
        else if(isdigit(a[0]))
        {
          //cout<<"int"<<endl;
          struct tree *t;
          t=new tree();
          t->flag='i';
          t->v=a;
          if(R==NULL)
          {
            R=t;
            cn=R;
          }
          else cn=addtree(cn,t);
        }
        else if(a.size())
        {
          //cout<<a<<"fool"<<endl;
          //cout<<"var"<<endl;
          struct tree *t;
          t=new tree();
          t->flag='s';
          t->v=a;
          if(R==NULL)
          {
            R=t;
            cn=R;
          }
          else cn=addtree(cn,t);
        }
      }

      //cout<<"pot"<<endl;

      if(R->v=="=")
      {
          struct block *B;
          B=new block();
          B->s=R->l->v;
          B->value=evaluate(R->r,A);
          A.push_back(B);
      }
      else
      {
        cout<<evaluate(R,A)<<endl;
      }
    }
  }
}
