#include <bits/stdc++.h>
using namespace std;

/*
Given an array, for each element find the value of the nearest element to the right which is having a frequency greater than that of the current element. If there does not exist an answer for a position, then make the value ‘-1’.
*/

vector<int> nextGreaterElementWithGreaterFrequency(vector<int> &nums)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;
    stack<int> s;
    s.push(0);
    int n = nums.size();
    vector<int> res(n, -1);

    for (int i = 1; i < nums.size(); i++)
    {

        if (mp[nums[s.top()]] > mp[nums[i]])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && mp[nums[s.top()]] < mp[nums[i]])
            {
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        res[s.top()] = -1;
        s.pop();
    }
    return res;
}

/*
Given a stack of integers, sort it in ascending order using another temporary stack.
*/

stack<int> sortUsingStack(stack<int> st)
{
    if (st.empty())
        return;
    stack<int> temp;
    temp.push(st.top());
    st.pop();
    while (!st.empty())
    {
        if (st.top() > temp.top())
        {
            temp.push(st.top());
            st.pop();
        }
        else
        {
            int top = st.top();
            st.pop();
            while (!temp.empty() && !st.empty() && temp.top() > top)
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(top);
        }
    }
    return temp;
}

/*
Given a Queue consisting of first **n** natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:

1. Push and pop elements from the stack
2. Pop (Or Dequeue) from the given Queue.
3. Push (Or Enqueue) in the another Queue.
*/
bool checkSorted(int n, queue<int> &q)
{
    stack<int> st;
    int expected = 1;
    int fnt;

    while (!q.empty())
    {
        fnt = q.front();
        q.pop();

        if (fnt == expected)
            expected++;

        else
        {
            if (st.empty())
            {
                st.push(fnt);
            }

            else if (!st.empty() && st.top() < fnt)
            {
                return false;
            }

            else
                st.push(fnt);
        }

        while (!st.empty() && st.top() == expected)
        {
            st.pop();
            expected++;
        }
    }

    if (expected - 1 == n && st.empty())
        return true;

    return false;
}

/*
Given a number , write a program to reverse this number using stack.
*/

int reverseNumUsingStack(int num)
{
    stack<int> st;
    while (num != 0)
    {
        st.push(num % 10);
        num = num / 10;
    }
    int i = 1;
    while (!st.empty())
    {
        num = num + st.top() * i;
        i = i * 10;
    }
    return num;
}

/*
Given an integer k and a **[queue](https://www.geeksforgeeks.org/queue-data-structure/)** of integers, The task is to reverse the order of the first **k** elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

- **enqueue(x) :** Add an item x to rear of queue
- **dequeue() :** Remove an item from front of queue
- **size() :** Returns number of elements in queue.
- **front() :** Finds front item.
*/

void reverseKelementsOfQueue(queue<int> q, int k)
{
    stack<int> s;

    int n = q.size();
    int m = n - k;
    while (!q.empty() && k--)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    while (!q.empty() && m--)
    {
        q.push(q.front());
        q.pop();
    }
}

/*
Given a sequence of n strings, the task is to check if any two similar words come together and then destroy each other then print the number of words left in the sequence after this pairwise destruction.

*/

int pairWiseDestruction(vector<string> seq)
{
    stack<string> st;
    st.push(seq[0]);
    for (int i = 1; i < seq.size(); i++)
    {
        if (!st.empty() && st.top() == seq[i])
        {
            st.pop();
            continue;
        }
        st.push(seq[i]);
    }
    return st.size();
}

/*
Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of every element in the array.

**Note:** If there is no smaller element on right side or left side of any element then we take zero as the smaller element. For example for the leftmost element, the nearest smaller element on the left side is considered as 0. Similarly, for rightmost elements, the smaller element on the right side is considered as 0.
*/
void leftSmaller(int arr[], int n, int SE[])
{
    stack<int> S;

    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && S.top() >= arr[i])
            S.pop();

        if (!S.empty())
            SE[i] = S.top();

        else
            SE[i] = 0;

        S.push(arr[i]);
    }
}

int findMaxDiff(int arr[], int n)
{
    int LS[n];

    leftSmaller(arr, n, LS);

    int RRS[n];
    reverse(arr, arr + n);
    leftSmaller(arr, n, RRS);

    int result = -1;
    for (int i = 0; i < n; i++)
        result = max(result, abs(LS[i] - RRS[n - 1 - i]));

    return result;
}
