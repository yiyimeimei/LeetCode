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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = new ListNode(0, head);
        ListNode *pre = newHead;
        while(head != nullptr)
        {
            if(head->val == val)
            {
                pre->next = head->next;
                ListNode *del = head;
                head = head->next;
                delete del;
            }
            else
            {
                pre = head;
                head = head->next;
            }
        }
        return newHead->next;
    }
};