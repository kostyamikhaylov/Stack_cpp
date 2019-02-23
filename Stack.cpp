#include <iostream>
using namespace std;

#define MAX_CAPACITY 256


class Stack
{
	public:
		Stack (void)
		{
			size_ = 0;
		}
		~Stack (void) {};
		void Push (int new_value);
		int Pop (void);
		void Dump (void);
	
	private:
		int data_[MAX_CAPACITY];
		int size_;
};

void Stack::Push (int new_value)
{
	if (size_ == MAX_CAPACITY)
	{
//		cout << "Stack is full\n";
		return ;
	}

	data_[size_++] = new_value;
}

int Stack::Pop (void)
{
	if (!size_)
	{
//		cout << "Error: Attempt to read from empty stack\n";
		return 0;
	}
	
	return data_[--size_];
}

void Stack::Dump (void)
{
	if (!size_)
	{
//		cout << "Stack is empty\n";
		return ;
	}
	while (size_)
	{
		cout << data_[--size_] << ' ';
	}
	cout << '\n';
}

bool Unittests (void);

int main ()
{
	return Unittests ();
}

bool Unittests (void)
{
	bool error = false;
	Stack stk1;
	
	stk1.Push (5);
	if (5 != stk1.Pop ())
	{
		cout << "Unittest #1 failed: Push and Pop don't work correctly\n";
		error = true;
	}

	Stack stk2;
	for (int i = 0; i < MAX_CAPACITY + 10; i++)
		stk2.Push (i);
	for (int i = MAX_CAPACITY - 1; i >= 0; i--)
	{
		if (i != stk2.Pop ())
			error = true;
	}
	if (error)
		cout << "Unittest #2 failed: Problems with capacity\n";

	return error;
}

