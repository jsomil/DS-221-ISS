#include<iostream>
#define MAX 1000

using namespace std;

template <class T>
class Stack
{
private:
	int top;
        T a[MAX];

	
public:
	
        Stack()  { top = -1; }
        bool push(int x)		
	{
	    if (top >= (MAX-1))
	    {
	        cout << "Stack Overflow";
	        return false;
	    }
	    else
	    {
	        a[++top] = x;
	        return true;
	    }
	}
	 
	T pop()
	{
	    if (top < 0)
	    {
	        cout << "Stack Underflow";
	        return 0;
	    }
	    else
	    {
	        T x = a[top--];
	        return x;
	    }
	}
 
	bool isEmpty()
	{
	    return (top < 0);
	}

        void peak()

        {
          cout<<"\nElement on top "<<a[top]<<endl;
        }
};
