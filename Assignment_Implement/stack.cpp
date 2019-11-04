#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
	int size();
};

int Stack::size()
{
	return top+1;
}

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		//cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "Cannot pop while stack is Empty"<<endl;
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty"<<endl;
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

// Driver program to test above functions
int main()
{
	class Stack s;
	cout<<s.size()<<endl;
	s.push(50);
	cout<<s.size()<<endl;
	s.push(100);
	cout<<s.size()<<endl;
	s.push(200);
	cout<<s.size()<<endl;
	cout << s.pop() << " is popped from stack"<<endl;
	cout<<s.size()<<endl;
	cout << s.pop() << " is popped from stack"<<endl;
	cout<<s.size()<<endl;
	cout << s.pop() << " is popped from stack"<<endl;
	cout<<s.size()<<endl;
	cout << s.pop();
	return 0;
}
