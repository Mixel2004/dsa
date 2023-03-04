#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int count, int N) {
   if(count == N/2) {
      inputStack.pop();
      return;
   }
   int x = inputStack.top();
   inputStack.pop();
   solve(inputStack, count + 1, N);
   inputStack.push(x);
}

void deleteMiddle(stack<int>&inputStack, int N){
	solve(inputStack, 0, N);
}
