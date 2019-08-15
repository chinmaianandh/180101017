#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int x;
	int y;
	node *p;
};

node *AddFirst(node *head,int a,int b)
{
	node *temp = new node();
	temp->x=a;
	temp->y=b;
	temp->p=head;
	return temp;
}

node *DelFirst(node *head)
{
	if(head==NULL)
	{
		cout<<"-1"<<endl;
		return head;
	}
	else
	{
		node *temp;
		temp=head->p;
		free(head);
		return temp;
	}
}

node *Del(node *head,int a,int b)
{
	if(head==NULL)
	{
		cout<<"-1"<<endl;
		return head;
	}
	else
	{
		char o='o';
		if((head->x==a)&&(head->y==b)) return DelFirst(head);
		node *temp;
		temp=head;
		while(temp->p!=NULL)
		{
			if((temp->p->x==a)&&(temp->p->y==b))
			{
				o='p';
				node *temp2=temp->p;
				temp->p=temp->p->p;
				free(temp2);
				break;
			}
			temp = temp->p;
		}
		if(o=='o') cout<<"-1"<<endl;
	}
	return head;
}

void Search_Dist(node *head,float d)
{
	int count=0;
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		int a=temp->x;
		int b=temp->y;
		if(a*a+b*b<=d*d)
		{
			count++;
		}
		temp = temp->p;
	}
	cout<<count<<endl;
}

bool Search(node *head,int a,int b)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if((temp->x==a)&&(temp->y==b))
		{
			return true;
		}
		temp = temp->p;
	}
	return false;
}

int Length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->p;
    }

    return count;
}

int main()
{
	node *head=NULL;
	int f;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>f;
		switch(f)
		{
			case 1:{
			int a,b;
			cin>>a>>b;
			head = AddFirst(head,a,b);
					}break;
			case 2:{
			head = DelFirst(head);
					}break;
			case 3:{
			int a,b;
			cin>>a>>b;
			head = Del(head,a,b);
					}break;
			case 4:{
			float d;
			cin>>d;
			Search_Dist(head,d);
					}break;
			case 5:{
			int a,b;
			cin>>a>>b;
			if (Search(head,a,b)) cout<<"True"<<endl;
			else cout<<"False"<<endl;
					}break;
			case 6:{
			cout<<Length(head)<<endl;
					}break;
		}
	}
}
