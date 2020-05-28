#include <iostream>
#include "ctemp.h"

using namespace std;

int main()
{
	Stack<int> s;
	s.push(10);
	s.peak();
    s.push(20);
    s.peak();
    s.push(30);
    s.peak();
    
    
    cout << s.pop() << " Popped from stack\n";
	s.peak();
	
    /*Stack<char> s;
	s.push('a');
	s.peak();
    s.push('b');
    s.peak();
    s.push('c');
    s.peak();
    
    
    cout << s.pop() << " Popped from stack\n";
	s.peak();
	*/
	return 0;
}
