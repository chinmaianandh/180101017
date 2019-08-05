#include<iostream>
#include<string>
#include<stack>
using namespace std;
int Is_prime(string);
string Multiply_fun(string,string);
string Add_fun(string,string);
string Div_fun(string,string,char);


int main()
{
  int t;
  string a;
  cin>>t;
  while(t!=0)
  {
    cin>>a;
    if(Is_prime(a))
    {
      cout<<"Prime"<<"\n";
    }
    else
    {
      cout<<"Not a Prime"<<"\n";
    }
    t--;
  }
}

int Is_prime(string a)
{
  //cout<<"ko"<<"\n";
  int c=0;
    string d,d2;
    d="2";
    d2="2";
    //cout<<"ko1"<<"\n";
    //cout<<a<<"\n";
    //cout<<Multiply_fun(d2,d)<<"\n";
    //cout<<Div_fun(a,d,'r');
    while((a.size()>Multiply_fun(d,d).size())||((a.size()==Multiply_fun(d,d).size())&&(a>Multiply_fun(d,d))))
    {
        //cout<<"ko2"<<"\n";
        //cout<<d<<"\n";
        if(Div_fun(a,d,'r')=="0") c++;
        if(c!=0) return 0;
        d=Add_fun(d,"1");
    }
    //cout<<"ko3"<<"\n";
    if(Div_fun(a,d,'r')=="0") return 0;
    else return 1;
}



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

  if(a=="1") return b;
  else if(b=="1") return a;
  else if((a=="2")&&(b=="2")) return "4";
  else if((a=="3")&&(b=="2")) return "6";
	else if((b=="3")&&(a=="2")) return "6";
	else if((a=="3")&&(b=="3")) return "9";

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
