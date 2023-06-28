#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode *random;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
        this->bottom = NULL;
        this->random = NULL;
    }
};

/*
Given a linked list of **N** nodes such that it may contain a loop.

A loop here means that the last ListNode of the link list is connected to the ListNode at position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last ListNode which is forming the loop.
*/

void removeCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    bool flag = false;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        slow = head;
        ListNode *temp;
        while (slow != fast)
        {
            temp = fast;
            slow = slow->next;
            fast = fast->next;
        }
        temp->next = NULL;
    }
}

/*
A number N is represented in Linked List such that each digit corresponds to a ListNode in linked list. You need to add 1 to it.
*/

int addOne(ListNode *head)
{
    queue<int> q;
    while (head != NULL)
    {
        q.push(head->val);
        head = head->next;
    }
    int ans = 0;
    while (!q.empty())
    {
        ans = ans * 10 + q.front();
        q.pop();
    }
    return ans + 1;
}

/*
Given a Linked List of size N, where every ListNode represents a sub-linked-list and contains two pointers:(i) a next pointer to the next ListNode,(ii) a bottom pointer to a linked list where this ListNode is head.Each of the sub-linked-list is in sorted order.Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. Note: The flattened list will be printed using the bottom pointer instead of next pointer.
*/

ListNode *flatterMultilevelLinkedList(ListNode *head)
{
}

/*
You are given a special linked list with **N** nodes where each ListNode has a next pointer pointing to its next ListNode. You are also given **M** random pointers, where you will be given **M** number of pairs denoting two nodes **a** and **b**  **i.e. a->arb = b** (arb is pointer to random ListNode)**.**

Construct a copy of the given list. The copy should consist of exactly **N** new nodes, where each new ListNode has its value set to the value of its corresponding original ListNode. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes **X** and **Y** in the original list, where **X.arb** **-->** **Y**, then for the corresponding two nodes **x** and **y** in the copied list, **x.arb --> y.**
*/
ListNode *copyRandomList(ListNode *head)
{
    unordered_map<ListNode *, ListNode *> m;
    ListNode *cursor = head;
    while (cursor)
    {
        ListNode *temp = new ListNode(cursor->val);
        m[cursor] = temp;
        cursor = cursor->next;
    }
    cursor = head;
    while (cursor)
    {
        if (cursor->next != NULL)
            m[cursor]->next = m[cursor->next];
        if (cursor->random != NULL)
            m[cursor]->random = m[cursor->random];
        cursor = cursor->next;
    }

    return m[head];
}

/*
Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return *the reordered list*.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.
*/

ListNode *oddEven(ListNode *head)
{
    ListNode *odd = new ListNode(-1);
    ListNode *even = new ListNode(-1);
    ListNode *t1 = odd, *t2 = even;
    int count = 1;
    while (head)
    {
        if (count % 2 == 0)
        {
            t2->next = head;
            t2 = t2->next;
        }
        else
        {
            t1->next = head;
            t1 = t1->next;
        }
        count++;
        head = head->next;
    }
    t1->next = even;
    t2->next = NULL;

    return odd;
}

/*
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list
*/

ListNode *leftShift(ListNode *head, int k)
{
    ListNode *temp = head;
    k--;
    while (k--)
    {
        temp = temp->next;
    }
    ListNode *newHead = temp->next;
    temp->next = NULL;
    temp = newHead;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
    return newHead;
}

/*
You are given the `head` of a linked list with `n` nodes.

For each node in the list, find the value of the **next greater node**. That is, for each node, find the value of the first node that is next to it and has a **strictly larger** value than it.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the `ith` node (**1-indexed**). If the `ith` node does not have a next greater node, set `answer[i] = 0`.
*/

int size(ListNode *head)
{
    ListNode *temp = head;
    int sz = 0;
    while (temp)
    {
        temp = temp->next;
        sz++;
    }
    return sz;
}

vector<int> nextGreaterNode(ListNode *head)
{
    int sz = size(head);
    vector<int> ans(sz + 1, 0);
    stack<pair<int, int>> st;
    int count = 1;
    while (head)
    {
        if (!st.empty() && head->val > st.top().first)
        {
            int g = head->val;
            while (!st.empty() && g > st.top().first)
            {
                ans[st.top().second] = g;
                st.pop();
            }
        }
        st.push({head->val, count++});
        head = head->next;
    }
    return ans;
}

/*
<aside>
💡 **Question 8**

Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to `0` until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of `ListNode` objects.)

</aside>
*/

ListNode *removeZeroSumSublists(ListNode *head)
{

    ListNode *root = new ListNode(0);
    root->next = head;
    unordered_map<int, ListNode *> um;
    um[0] = root;
    int ac = 0;

    while (head != NULL)
    {
        ac += head->val;

        if (um.find(ac) != um.end())
        {
            ListNode *prev = um[ac];
            ListNode *start = prev;

            int aux = ac;
            while (prev != head)
            {
                prev = prev->next;
                aux += prev->val;
                if (prev != head)
                    um.erase(aux);
            }

            start->next = head->next;
        }
        else
        {
            um[ac] = head;
        }

        head = head->next;
    }

    return root->next;
}