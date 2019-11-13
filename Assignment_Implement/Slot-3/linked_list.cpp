#include<bits/stdc++.h>
using namespace std;

struct node
{
  node *prev=NULL;
  int value;
  node *next=NULL;
};

class LL
{
  node *head=NULL;
  node *tail=NULL;
  int si=0;

public:
  int size();
  node *begin();
  node *end();
  void push_front(int x);
  void push_back(int x);
  int pop_front();
  int pop_back();
  int front();
  int back();
  node *searchfor(int x);
  void remove(node *n);
  void insert_after(int x, node *n);
  void insert_before(int x, node *n);
  void print_LL();
};

int LL::size()
{
  return si;
}

node *LL::begin()
{
  return head;
}

node *LL::end()
{
  return tail;
}

void LL::push_front(int x)
{
  node *temp=new node;
  temp->value=x;
  if(head==NULL)
  {
    si++;
    head=temp;
    tail=temp;
    return;
  }
  else
  {
    si++;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return;
  }

}

void LL::push_back(int x)
{
  node *temp=new node;
  temp->value=x;
  if(tail==NULL)
  {
    si++;
    head=temp;
    tail=temp;
    return;
  }
  else
  {
    si++;
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    return;
  }
}

int LL::pop_front()
{
  if(head==NULL)
  {
    cout<<"Cannot pop front when LL is empty. Returned 0 by default."<<endl;
    return 0;
  }
  else
  {
    si--;
    node *temp=head;
    if(head==tail)
    {
      int y=temp->value;
      head=NULL;
      tail=NULL;
      delete temp;
      return y;
    }
    else
    {
      head=head->next;
      head->prev=NULL;
      int y=temp->value;
      delete temp;
      return y;
    }
  }
}

int LL::pop_back()
{
  if(tail==NULL)
  {
    cout<<"Cannot pop back when LL is Empty. Returned 0 by default."<<endl;
    return 0;
  }
  else if(head==tail)
  {
    si--;
    node *temp=tail;
    head=NULL;
    tail=NULL;
    int y=temp->value;
    delete temp;
    return y;
  }
  else
  {
    si--;
    node *temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    int y=temp->value;
    delete temp;
    return y;
  }
}

int LL::front()
{
  if(head==NULL)
  {
    cout<<"LL is Empty. Returned 0 by default."<<endl;
    return 0;
  }
  else return head->value;
}

int LL::back()
{
  if(tail==NULL)
  {
    cout<<"LL is Empty. Returned 0 by default."<<endl;
    return 0;
  }
  else return tail->value;
}

node *LL::searchfor(int x)
{
  node *temp=head;
  while(temp)
  {
    if(temp->value==x) return temp;
    temp=temp->next;
  }
  return NULL;
}

void LL::remove(node *n)
{
  if(n==NULL) return;
  si--;
  node *temp=n;
  if(n->next)  n->next->prev=n->prev;
  else tail=tail->prev;
  if(n->prev)  n->prev->next=n->next;
  else head=head->next;
  delete temp;
}

void LL::insert_after(int x, node *n)
{
  if(n==NULL) return;
  node *temp=new node;
  temp->value=x;
  if(n->next)
  {
    n->next->prev=temp;
    temp->next=n->next;
  }
  n->next=temp;
  temp->prev=n;
  if(tail==n) tail=temp;
  si++;
}

void LL::insert_before(int x, node *n)
{
  if(n==NULL) return;
  node *temp=new node;
  temp->value=x;
  if(n->prev!=NULL)
  {
    n->prev->next=temp;
    temp->prev=n->prev;
  }
  temp->next=n;
  n->prev=temp;
  if(head==n) head=temp;
  si++;
}

void LL::print_LL()
{
  node *temp=head;
  while(temp)
  {
    cout<<temp->value<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

int main()
{
  LL L;
  L.print_LL();
  L.push_front(5);
  L.print_LL();
  L.push_back(6);
  L.print_LL();
  L.insert_before(4,L.searchfor(5));
  L.print_LL();
  L.insert_after(7,L.searchfor(4));
  L.print_LL();
  cout<<"size: "<<L.size()<<endl;
  L.remove(L.searchfor(4));
  L.print_LL();
  L.remove(L.searchfor(6));
  L.print_LL();

  cout<<"size: "<<L.size()<<endl;
  cout<<"front: "<<L.front()<<endl;
  cout<<"back: "<<L.back()<<endl;

  L.print_LL();
  L.pop_back();
  L.print_LL();
  L.pop_back();
  L.print_LL();
  L.pop_back();
}
