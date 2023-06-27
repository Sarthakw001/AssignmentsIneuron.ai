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
class ListNodeD
{
public:
    int val;
    ListNodeD *next;
    ListNodeD *prev;

    ListNodeD(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

/*
Given two linked list of the same size, the task is to create a new linked list using those linked lists. The condition is that the greater node among both linked list will be added to the new linked list.
*/

ListNode *greaterNode(ListNode *head1, ListNode *head2)
{
    ListNode *newLL = new ListNode(-1);
    ListNode *temp = newLL;
    while (head1 != NULL)
    {
        ListNode *t = new ListNode(-1);
        if (head1->val > head2->val)
        {
            t->val = head1->val;
            temp->next = t;
            temp = temp->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else
        {
            t->val = head2->val;
            temp->next = t;
            temp = temp->next;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return newLL->next;
}

/*
Write a function that takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. The list should only be traversed once.

For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates() should convert the list to 11->21->43->60.
*/

void removeDuplicates(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (temp->val == temp->next->val)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
}

/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).
*/

ListNode *reverseKGroup(ListNode *head, int k)
{
    stack<ListNode *> st;
    ListNode *newLL = new ListNode(-1), *temp2 = newLL;
    while (head != NULL)
    {
        st.push(head);
        head = head->next;
        if (st.size() == k)
        {
            while (!st.empty())
            {
                temp2->next = st.top();
                st.pop();
                temp2 = temp2->next;
            }
        }
    }
    vector<ListNode *> v;
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        temp2->next = v[i];
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    return newLL->next;
}

/*
Given a linked list, write a function to reverse every alternate k nodes (where k is an input to the function) in an efficient way. Give the complexity of your algorithm.
*/

ListNode *reverseKGroup(ListNode *head, int k)
{
    stack<ListNode *> st;
    ListNode *newLL = new ListNode(-1), *temp2 = newLL;
    bool flag = true;
    while (head != NULL)
    {
        st.push(head);
        head = head->next;
        if (st.size() == k)
        {
            if (flag)
            {
                while (!st.empty())
                {
                    temp2->next = st.top();
                    st.pop();
                    temp2 = temp2->next;
                }
                flag = false;
            }
            else
            {
                vector<ListNode *> v;
                while (!st.empty())
                {
                    v.push_back(st.top());
                    st.pop();
                }

                for (int i = v.size() - 1; i >= 0; i--)
                {
                    temp2->next = v[i];
                    temp2 = temp2->next;
                }
                flag = true;
            }
        }
    }
    vector<ListNode *> v;
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        temp2->next = v[i];
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    return newLL->next;
}

/*
Given a linked list and a key to be deleted. Delete last occurrence of key from linked. The list may have duplicates
*/

ListNode *reverseLL(ListNode *head)
{
    ListNode *curr = head, *prev = NULL;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void removeLastOccurence(ListNode *head, int key)
{
    ListNode *h1 = reverseLL(head);
    ListNode *temp = h1;
    if (temp->next == NULL && temp->val == key)
    {
        delete temp;
        return;
    };
    while (temp->next != NULL)
    {
        if (temp->next->val == key)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    reverseLL(h1);
}

/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the lists (in place) and return the head of the merged list.
*/

ListNode *mergeSortedList(ListNode *head1, ListNode *head2)
{
    ListNode *newLL = new ListNode(-1), *temp = newLL;

    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            temp->next = new ListNode(head1->val);
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = new ListNode(head2->val);
            temp = temp->next;
            head2 = head2->next;
        }
    }
    while (head1)
    {
        temp->next = new ListNode(head1->val);
        temp = temp->next;
        head1 = head1->next;
    }
    while (head2)
    {
        temp->next = new ListNode(head2->val);
        temp = temp->next;
        head1 = head1->next;
    }
    return newLL->next;
}

/*Given a Doubly Linked List, the task is to reverse the given Doubly Linked List*/

ListNodeD *reverseDoublyLinkedList(ListNodeD *head)
{
    ListNodeD *curr = head, *prev = NULL;
    while (curr)
    {
        ListNodeD *next = curr->next;
        curr->next = prev;
        curr->prev = next;

        prev = curr;
        curr = next;
    }
    return prev;
}

/*
Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.
*/
void deleteFromDoublyLL(ListNodeD *head, int x)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        if (count == x)
        {
            ListNodeD *t = head->next;
            head->val = head->next->val;
            head->next = head->next->next;
            head->next->prev = head;
            delete t;
        }
        head = head->next;
    }
}