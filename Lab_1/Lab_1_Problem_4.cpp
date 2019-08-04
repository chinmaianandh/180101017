#include<iostream>
#include<string>
#include<stack>
using namespace std;


string Add_fun(string a,string b)
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

string Subtract_fun(string a,string b)
{

	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
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


	int k;
	while(s2.size()!=0)
	{
		k = s1.top()-s2.top();
		if(c==1)
		{
			k--;
			c=0;
		}
		if(k<0)
    {
      c=1;
      k+=10;
    }
		ans.push(k);
		s1.pop();s2.pop();
	}
	while(s1.size()!=0)
	{
		k = s1.top();
		if(c==1)
		{
			k--;
			c=0;
		}
    if(k<0)
    {
      c=1;
      k+=10;
    }

		ans.push(k);
		s1.pop();
	}
  if(ans.top()==0) ans.pop();


	if(c==1)
	{
    return "Error : The output is not a Natural Number.";
	}


	while(ans.size()!=0)
	{
		string s(1,'0'+ans.top());
		out.append(s);
		ans.pop();
	}

  if (out=="") return "0";
  else return out;

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
      out = Add_fun(out,st);
      temp.pop();
    }
    s1.pop();
  }
  return out;


}

string Div_fun(string a,string b,char p)
{
    while(a[0]=='0')
    {
        a.erase(a.begin()+0);
    }
    while(b[0]=='0')
    {
        b.erase(b.begin()+0);
    }

    if(b.size()<2)
    {
      int bi=stoi(b);
      long long int ai=stoi(a);
      string qi=to_string(ai/bi);
      string ri=to_string(ai%bi);
      if(p=='q') return qi;
      else if(p=='r') return ri;
    }

    string Multiples[11];
    Multiples[0]="0";
    int i=0;
    while (i<10)
    {
        Multiples[i+1]=Add_fun(Multiples[i],b);
        //cout<<Multiples[i]<<"\n";
        i++;
    }
    string a1;
    string qo="";
    //string re;
    while(a!="")
    {
        if (qo=="")
        {
            a1=a.substr(0,b.size());
            a.erase(0,b.size());
            //cout<<a1<<" "<<a<<"\n";
        }
        else
        {
          string s(1,a[0]);
          //cout<<"ko"<<s<<"\n";
            a1.append(s);
          //  cout<<"a1:"<<a1<<"\n";
            a.erase(a.begin()+0);
        }
        for(int i=0;i<10;i++)
        {
        //  cout<<"lol"<<"\n";
            if(((Multiples[i].size()==a1.size())&&(a1.size()==Multiples[i+1].size())&&(Multiples[i]<=a1)&&(a1<Multiples[i+1]))||((Multiples[i].size()==a1.size())&&(a1.size()<Multiples[i+1].size())&&(Multiples[i]<=a1))||((Multiples[i].size()<a1.size())&&(a1.size()==Multiples[i+1].size())&&(a1<Multiples[i+1])))
            {
                qo.append(to_string(i));
                a1 = Subtract_fun(a1,Multiples[i]);
                //cout<<a<<"\n"<<a1<<"\n"<<qo<<"\n";
            }
        }

    }
    if(qo[0]=='0') qo.erase(qo.begin()+0);
    //cout<<"kkkk"<<"\n"<<qo<<" "<<a1<<"\n";
    if(p=='q') return qo;
    else if (p=='r') return a1;
}

int main()
{
	int t;
	cin>>t;
	string ansq[t];
	string ansr[t];
	string a,b;
	int i=0;
	while(t!=i)
	{
		cin>>a;
		cin>>b;
		ansq[i]=Div_fun(a,b,'q');
		ansr[i]=Div_fun(a,b,'r');
		i++;
	}
	i=0;
	while(t!=i)
	{
		cout<<ansq[i]<<"\n"<<ansr[i]<<"\n";
		i++;
	}
}
