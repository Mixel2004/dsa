#include <bits/stdc++.h> 
class NStack
{
private:
    int * arr;
    int * next;
    int * tops;
    int freespace;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        next = new int[S];
        tops = new int[N];
        freespace = 0;

        for(int i = 0; i < N; i++) {
            tops[i] = -1;
        }

        for(int i = 0; i < S; i++) {
            next[i] = i+1;
        }
        next[S-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespace == -1) return false;
        int index = freespace;
        arr[index] = x;
        freespace = next[index];
        next[index] = tops[m-1];
        tops[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(tops[m-1] == -1) return -1;
        int index= tops[m-1];
        int value = arr[index];
        tops[m-1] = next[index];
        next[index] = freespace;
        freespace = index;
        return value;
    }
};
