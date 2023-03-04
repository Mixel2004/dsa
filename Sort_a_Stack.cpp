#include <bits/stdc++.h> 

void sortInsert(stack<int> &s, int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}
	int t = s.top();
	if(t<=x) {
		s.push(x);
		return;
	}
	s.pop();
	sortInsert(s, x);
	s.push(t);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;
	int x = stack.top();
	stack.pop();
	sortStack(stack);
	sortInsert(stack, x);
}
