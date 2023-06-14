#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

/*
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.If the input linked list is NULL or has 1 ListNode, then it should return NULL
*/

int lengthLL(ListNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
ListNode *deleteMiddle(ListNode *head)
{
    int n = lengthLL(head);

    if (n == 1 || n == 0)
    {
        return NULL;
    }

    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (count == n / 2 - 1)
        {
            ListNode *d = temp->next;
            temp->next = temp->next->next;
            delete d;
            break;
        }
        count++;
        temp = temp->next;
    }
    return head;
}
/*
Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.
*/

bool hasCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

/*
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.
*/

ListNode *NthLastNode(ListNode *head, int n)
{
    ListNode *slow = head, *fast = head;
    while (fast && n > 0)
        fast = fast->next;
    if (n > 0 && fast == NULL)
        return NULL;
    if (fast == NULL)
        return head->next;
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

/*
Given a singly linked list of characters, write a function that returns true if the given list is a palindrome, else false.
*/

bool isPalindrome(ListNode *head)
{
    stack<int> s;
    ListNode *temp = head;
    while (temp != NULL)
    {
        s.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (!s.empty())
    {
        int temp1 = s.top();
        s.pop();
        if (temp->val != temp1)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

/*
Given a linked list of **N** nodes such that it may contain a loop.

A loop here means that the last ListNode of the link list is connected to the ListNode at position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last ListNode which is forming the loop.
*/

void removeCycle(ListNode *head)
{
    unordered_map<ListNode *, int> mp;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        if (mp.find(temp->next) != mp.end())
        {
            temp->next = NULL;
            return;
        }
        mp[temp] = temp->val;
        temp = temp->next;
    }
}

/*
Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till end of the linked list.
*/

void modifyLL(ListNode *head, int M, int N)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        cnt++;
        int n = N;
        if (M == cnt)
        {
            cnt = 0;
            while (n != 0 && temp != NULL && temp->next != NULL)
            {
                temp->next = temp->next->next;
                n--;
            }
        }
        temp = temp->next;
    }
}

/*
Given two linked lists, insert nodes of second list into first list at alternate positions of first list.
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.

Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion must be done in-place. Expected time complexity is O(n) where n is number of nodes in first list.
*/

/*
Given a singly linked list, find if the linked list is [circular] or not.

> A linked list is called circular if it is not NULL-terminated and all nodes are connected in the form of a cycle. Below is an example of a circular linked list.
>
*/

bool circularLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (temp->next == head)
            return true;
        temp = temp->next;
    }
    return false;
}
