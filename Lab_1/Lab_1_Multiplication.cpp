#include<iostream>
#include<string>
#include<stack>
using namespace std;


string add_fun(string a,string b)
{
	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
	stack<int> ans;


	if(a.size()>=b.size())
	{
		int n1 = a.size();
		int n2 = b.size();
		for(int i=0;i< n1;i++)
		{
			if(s1.size()!=0 || a[i]!='0') s1.push(a[i]-'0');
		}
		for(int i = 0; i < n2; ++i)
		{
			if(s2.size()!=0 || b[i]!='0') s2.push(b[i]-'0');
		}
	}
	else
	{
		int n1 = b.size();
		int n2 = a.size();
		for(int i=0;i<n1;i++)
		{
			if(s1.size()!=0 || b[i]!='0') s1.push(b[i]-'0');
		}
		for(int i = 0; i <n2; ++i)
		{
			if(s2.size()!=0 || a[i]!='0') s2.push(a[i]-'0');
		}
	}


	int n1 = s1.size();
	int n2 = s2.size();


	int k;
	while(s2.size()!=0)
	{
		k = s1.top()+s2.top();
		if(c==1)
		{
			k++;
			c=0;
		}
		if(k>9)
			c=1;
		ans.push(k%10);
		s1.pop();s2.pop();
	}
	while(s1.size()!=0)
	{
		k = s1.top();
		if(c==1)
		{
			k++;
			c=0;
		}
		if(k>9)
			c=1;
		ans.push(k%10);
		s1.pop();
	}

	if(c==1)
	{
		ans.push(1);
	}


	while(ans.size()!=0)
	{
		string s(1,'0'+ans.top());
		out.append(s);
		ans.pop();
	}
	//if(ans.top()==0) ans.pop();
	return out;

}


string Multiply_fun(string a,string b)
{
  string out="0";

  stack<int> s1;
  stack<int> s2;
  stack<int> temp;
  stack<int> ans;


  int n1 = a.size();
  int n2 = b.size();
  for(int i=0;i< n1;i++)
  {
    if(s1.size()!=0 || a[i]!='0') s1.push(a[i]-'0');
  }
  for(int i = 0; i < n2; ++i)
  {
    if(s2.size()!=0 || b[i]!='0') s2.push(b[i]-'0');
  }


  for(int i=0;s1.size()!=0;i++)
  {
    temp=s2;
    for(int j=0;temp.size()!=0;j++)
    {
      string st = to_string(s1.top()*temp.top());
      int k=0;
      while(k!=i+j)
      {
        st.append("0");
        k++;
      }
      out = add_fun(out,st);
      temp.pop();
    }
    s1.pop();
  }
  return out;


}


int main()
{
  string a,b;
	cin>>a;
	cout<<'*'<<'\n';
	cin>>b;
	cout<<'='<<'\n';
	cout<< Multiply_fun(a,b)<<'\n';
}
