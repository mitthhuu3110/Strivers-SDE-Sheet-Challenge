#include <bits/stdc++.h> 

void insertStack(stack<int> &s, int num){
	if(s.empty() || s.top() < num){
		s.push(num);
		return;
	}

	int temp = s.top();
	s.pop();
	insertStack(s, num);
	s.push(temp);
}


void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	insertStack(stack, num);
}
