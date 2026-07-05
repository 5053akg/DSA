#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1;
        ListNode *t2 = l2;

        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        int carry = 0;

        while (t1 != nullptr || t2 != nullptr || carry)
        {
            int sum = carry;

            if (t1)
            {
                sum += t1->val;
                t1 = t1->next;
            }

            if (t2)
            {
                sum += t2->val;
                t2 = t2->next;
            }

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Linked List banane ka function
ListNode* createList(int n)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ListNode *newNode = new ListNode(x);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Print Linked List
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n1, n2;

    cout << "Enter size of first list: ";
    cin >> n1;

    cout << "Enter elements: ";
    ListNode *l1 = createList(n1);

    cout << "Enter size of second list: ";
    cin >> n2;

    cout << "Enter elements: ";
    ListNode *l2 = createList(n2);

    Solution obj;
    ListNode *ans = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(ans);

    return 0;
}