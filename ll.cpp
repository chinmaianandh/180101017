#include<iostream>
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
	node *temp;
	temp=head->p;
	free(head);
	return temp;
}

node *Del(node *head,int a,int b)
{
	if((head->x==a)&&(head->y==b)) return DelFirst(head);
	node *temp;
	temp=head;
	while(temp->p!=NULL)
	{
		if((temp->p->x==a)&&(temp->p->y==b))
		{
			node *temp2=temp->p;
			temp->p=temp->p->p;
			free(temp2);
			break;
		}
	}
	return head;
}

void Search_Dist(node *head,float d)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		int a=temp->x;
		int b=temp->y;
		if(a*a+b*b<=d*d)
		{
			cout<<"("<<a<<","<<b<<") ";
		}
	}
	cout<<endl;
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
	}
	return false;
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
			cout<<Search(head,a,b)<<endl;
					}break;
			case 6:{
			cout<<Length(head)<<endl;
					}break;
		}
	}
}
