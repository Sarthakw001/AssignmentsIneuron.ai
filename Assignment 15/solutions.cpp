#include <bits/stdc++.h>
using namespace std;

/*
iven an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.Next greater element of an element in the array is the nearest element on the right which is greater than the current element.If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
*/

vector<int> nextLargerElement(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    int k = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[k] = -1;
            k--;
        }
        else if (st.top() > arr[i] && !st.empty())
        {
            ans[k] = st.top();
            k--;
        }
        st.push(arr[i]);
    }
    return ans;
}

/*
<aside>
💡 **Question 2**

Given an array **a** of integers of length **n**, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

</aside>0
*/

vector<int> nextLargerElement(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    int k = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[k] = -1;
            k++;
        }
        else if (st.top() < arr[i] && !st.empty())
        {
            ans[k] = st.top();
            k++;
        }
        st.push(arr[i]);
    }
    return ans;
}

/*
Implement a Stack using two queues q1 and q2.
*/

class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int val)
    {
        q1.push(val);
    }
    void pop()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

/*
You are given a string S, the task is to reverse the string using stack.
*/

string revserse(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.
*/

int postfixExp(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            switch (s[i])
            {
            case '+':
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
                break;
            case '*':
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
                break;
            case '-':
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
                break;
            case '/':
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
                break;
            }
        }
    }
    return st.top();
}

/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.
*/

class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack(){}

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
        {
            int mn = min(val, st.top().second);
            st.push({val, min(val, mn)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

/*
<aside>
💡 **Question 8**

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

</aside>
*/