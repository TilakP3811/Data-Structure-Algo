/*Given the head of a singly linked list, return true if it is a palindrome.



Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseIt(ListNode *head)
{
    ListNode *cur = head, *nex;
    ListNode *pre = NULL;

    while (cur != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverseIt(slow->next);

    slow = slow->next;

    while (slow != NULL)
    {
        if (head->val != slow->val)
        {
            return false;
        }
        slow = slow->next;
        head = head->next;
    }
    return true;
}