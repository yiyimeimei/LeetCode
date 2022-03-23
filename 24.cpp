/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
        {
            return head;
        }
        ListNode *n1 = nullptr, *n2 = nullptr, *n3 = nullptr, *n4 = nullptr;
        n1 = head -> next;
        n4 = head;
        head -> next = n1 -> next;
        n1 -> next = head;
        ListNode* nextNode = n4 -> next;
        while((nextNode != nullptr) && (nextNode -> next != nullptr))
        {
            //cout<<nextNode->val<<endl;
            n2 = nextNode;
            n3 = nextNode -> next;
            nextNode = n3 -> next;
            n2 -> next = n3 -> next;
            n3 -> next = n2;
            n4 -> next = n3;
            n4 = n2;
        }
        return n1;
    }
};

int main()
{
    ListNode *a = new ListNode(15, nullptr);
    for(int i = 14; i > 0; --i)
    {
        ListNode *b = new ListNode(i, a);
        a = b;
    }
    ListNode *c = a;
    while(a != nullptr)
    {
        cout<<a->val<<endl;
        a = a->next;
    }
    Solution s;
    a = s.swapPairs(c);
    while(a != nullptr)
    {
        cout<<a->val<<endl;
        a = a->next;
    }
    return 0;
}