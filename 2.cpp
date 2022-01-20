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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        
        ListNode *currentNode;
        ListNode *nextNode = new ListNode(0, nullptr);
        ListNode *head = new ListNode(-1, nextNode);
        bool carry = false;
        while(l1 != nullptr && l2 != nullptr)
        {
            currentNode = nextNode;
            int sum = l1->val + l2->val;
            if(carry)
            {
                sum++;
            }
            if(sum > 9)
            {
                sum %= 10;
                carry = true;
            }
            else
            {
                carry = false;
            }
            currentNode->val = sum;
            nextNode = new ListNode(0, nullptr);
            currentNode->next = nextNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == nullptr)
        {
            while(l2 != nullptr)
            {
                currentNode = currentNode->next;
                int sum = l2->val;
                if(carry)
                {
                    sum++;
                }
                if(sum > 9)
                {
                    sum %= 10;
                    carry = true;
                }
                else
                {
                    carry = false;
                }
                currentNode->val = sum;
                ListNode* nextNode = new ListNode(123456, nullptr);
                currentNode->next = nextNode;
                l2 = l2->next;
            }
        }
        else if(l2 == nullptr)
        {
            while(l1 != nullptr)
            {
                currentNode = currentNode->next;
                int sum = l1->val;
                if(carry)
                {
                    sum++;
                }
                if(sum > 9)
                {
                    sum %= 10;
                    carry = true;
                }
                else
                {
                    carry = false;
                }
                currentNode->val = sum;
                ListNode* nextNode = new ListNode(123456, nullptr);
                currentNode->next = nextNode;
                l1 = l1->next;
            }
        }
        if(carry)
        {
            currentNode->next->val = 1;
        }
        else
        {
            currentNode->next = nullptr;
        }
        return head->next;
    }
};